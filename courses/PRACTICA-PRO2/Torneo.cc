/** @file Torneo.cc
  @brief Código de la clase Torneo
*/
#include "Torneo.hh"

Torneo::Torneo()
{
  categoria = 0;
  first_time = false;
}

Torneo::Torneo(int c)
{
  categoria = c;
  first_time = false;
}

Torneo::~Torneo(){}

void Torneo::iniciar_torneo(const Cjt_jugadores &r_global)
{
  leer_inscritos(r_global);
  cuadro = generar_cuadro_emparejamiento(1, 0);
  imprimir_cuadro_emparejamiento(cuadro);
  cout << endl;
}

void Torneo::finalizar_torneo(Cjt_jugadores &r_global, const Cjt_categorias &categ)
{
  // Calculamos la altura de nuestro árbol
  int h = log2(n_inscritos) + 1;

  // Leemos el árbol de resultados
  BinTree<string> a = leer_resultados(0, h);

  // Variable local con las estadísticas de los jugadores
  vector<Stats> stats(n_inscritos);

  // Establecemos los ganadores
  desarrollar_torneo(a, cuadro, categ, stats, 0);

  // Imprimimos resultados y actualizamos estadísitcas del ranking
  imprimir_cuadro_resultados(a, cuadro, r_global);
  restar_puntos_ultima_edicion(r_global);
  procesar_ranking_relativo(r_global, stats);
  r_global.ordenar_ranking();
}

void Torneo::baja_jugador(const string &nombre)
{
  pts_edicion_ant.erase(nombre);
}

int Torneo::consultar_categoria() const
{
  return categoria;
}

bool Torneo::torneo_jugado() const
{
  return first_time;
}

void Torneo::leer_inscritos(const Cjt_jugadores &r_global)
{
  int n;
  cin >> n_inscritos;
  vector<string> v(n_inscritos);
  for (int i = 0; i < n_inscritos; i++)
  {
    cin >> n;
    v[i] = r_global.consultar_nombre(n);
  }
  inscritos = v;
}

BinTree<int> Torneo::generar_cuadro_emparejamiento(int r, int l)
{
  // Calculamos el contrincante (a vs b)
 int b = pow(2, l+1) + 1 - r;

 // Mientras b no exceda la posición del último inscrito, generamos el subárbol
 if(b <= n_inscritos)
 {
   BinTree<int> left = generar_cuadro_emparejamiento(r, l+1);
   BinTree<int> right = generar_cuadro_emparejamiento(b, l+1);
   return BinTree<int> (r, left, right);
 }
 // En caso contrario, devolvemos un árbol sólo con el jugador r como raíz
 return BinTree<int> (r);
}

void Torneo::imprimir_cuadro_emparejamiento(const BinTree<int> &a) const
{
  // Si nos topamos con una hoja, escribimos el emparejamiento
  if (not a.empty()) 
  {
    if(a.left().empty() and a.right().empty()) cout << a.value() << "." << inscritos[a.value()-1];
    else
    {
      cout << "(";
      imprimir_cuadro_emparejamiento(a.left());
      cout << " ";
      imprimir_cuadro_emparejamiento(a.right());
      cout << ")";
    }
  }
}

void Torneo::restar_puntos_ultima_edicion(Cjt_jugadores &r)
{
  for (It_puntos it = pts_edicion_ant.begin(); it != pts_edicion_ant.end(); ++it)
  {
    r.sumar_puntos(it->first, - it->second);
  }
}

BinTree<string> Torneo::leer_resultados(int deep, int h)
{
  string x;
  cin >> x;
  if(x != "0")
  {
    // Si el nivel es menor que la altura, leemos los subárboles derecho e izquierdo
    if(deep < h){
      BinTree<string> l = leer_resultados(deep+1, h);
      BinTree<string> r = leer_resultados(deep+1,h);
      return BinTree<string>(x,l,r);
    }
    // Si llegamos a la altura máxima, se devuelve un árbol sin hijos, con el partido léido como raíz
    else if(h == deep) return BinTree<string>(x);
  }
  return BinTree<string>();
}

void Torneo::desarrollar_torneo(const BinTree<string> &a, BinTree<int> &cuadro, const Cjt_categorias &categ, vector<Stats>& stats, int lvl)
{
  if(not a.empty())
  {
    BinTree<int> i = cuadro.left();
    BinTree<int> d = cuadro.right();

    // Actualizamos primero los subárboles derecho e izquierdo
    desarrollar_torneo(a.left(), i, categ, stats, lvl+1);
    desarrollar_torneo(a.right(), d, categ, stats, lvl+1);

    // Consultamos quién es el ganador del enfrentamiento y sustituimos la raíz por este
    int winner = procesar_partido(a.value(), i.value(), d.value(), stats);
    cuadro = BinTree<int>(winner, i, d);
    
    // Calculamos los puntos y los asignamos
    stats[cuadro.value()-1].puntos = categ.consultar_puntos(categoria, lvl);
  }
  else
  {
    // Si se trata de una hoja, devolvemos la raíz y calculamos los puntos y los asignamos
    stats[cuadro.value()-1].puntos = categ.consultar_puntos(categoria, lvl);
    cuadro = BinTree<int>(cuadro.value());
  }
}

int Torneo::procesar_partido(const string &match, const int &a, const int &b, vector<Stats>& stats)
{
  int s_a, s_b, j_a, j_b;
  s_a = s_b = j_a = j_b = 0;
  // w será cierto si gana A, falso si gana B
  bool w;

  if(match.length() != 3)
  {
    // Calculamos juegos y sets de cada jugador
    for (int i = 0; i < match.length(); i+=4)
    {
      j_a += match[i] - '0';
      j_b +=match[i+2] - '0';

      if(match[i] > match[i+2]) ++s_a;
      else ++s_b;
    }

    // Añadimos los datos anteriores  al vector de estadísticas
    stats[a-1].sets_ganados += s_a;
    stats[a-1].sets_perdidos += s_b;

    stats[b-1].sets_ganados += s_b;
    stats[b-1].sets_perdidos += s_a;

    stats[a-1].juegos_ganados += j_a;
    stats[a-1].juegos_perdidos += j_b;

    stats[b-1].juegos_ganados += j_b;
    stats[b-1].juegos_perdidos += j_a;
    
    // Establecemos el ganador
    w = s_a > s_b;
  }
  else w = match[0]  > match[2];

  if(w)
  {
    // Si gana gana A, se le suma un partido ganado A y uno perdido a B
    ++stats[a-1].p_ganados;
    ++stats[b-1].p_perdidos;
    return a;
  }
  else
  {
    // Si gana gana B, se le suma un partido ganado B y uno perdido a A
    ++stats[b-1].p_ganados;
    ++stats[a-1].p_perdidos;
    return b;
  }
}

void Torneo::imprimir_cuadro_resultados(const BinTree<string> &a, const BinTree<int> &b, const Cjt_jugadores &r) const
{
  // Mientras no se trate de una hoja, se escribe la raíz de a (partido) y los hijos de b (contricantes)
  if(not a.empty() and not b.empty() and not b.right().empty() and not b.left().empty())
  {
    cout << "(";
    cout << b.left().value() << "." << inscritos[b.left().value() - 1];
    cout << " vs ";
    cout << b.right().value() << "." << inscritos[b.right().value() - 1];
    cout << " " << a.value();
    imprimir_cuadro_resultados(a.left(), b.left(), r);
    imprimir_cuadro_resultados(a.right(), b.right(), r);
    cout << ")";
  }
}

void Torneo::procesar_ranking_relativo(Cjt_jugadores &r_global, vector<Stats>& stats)
{
  // Creamos un nuevo diccionario para almacenar ahí los puntos de la edición actual
  cout << endl;
  map<string, int> new_m;

  for(int i = 0; i < n_inscritos; ++i)
  {
    // Se suman las estadísticas de cada jugador
    r_global.sumar_stats(inscritos[i], stats[i].puntos, stats[i].p_ganados, stats[i].p_perdidos,
                     stats[i].sets_ganados, stats[i].sets_perdidos, stats[i].juegos_ganados, stats[i].juegos_perdidos);

    //Si el jugador ha conseguido puntos, se añaden al nuevo diccionario y se escriben estos.
    if(stats[i].puntos > 0)
    {
      new_m.insert(make_pair(inscritos[i], stats[i].puntos));
      cout << i+1 << "." << inscritos[i] << " " << stats[i].puntos << endl;
    }
  }
  // Sustituimos el diccionario con los puntos de la edición anterior por el de la actual
  pts_edicion_ant = new_m;
  
  // Establecemos que el torneo ya se ha jugado como mínimo una vez
  first_time = true;
}

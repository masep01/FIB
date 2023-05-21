/** @file Cjt_jugadores.cc
    @brief Código de la clase Cjt_jugadores
*/

#include "Cjt_jugadores.hh"

Cjt_jugadores::Cjt_jugadores(){}

Cjt_jugadores::~Cjt_jugadores(){}

void Cjt_jugadores::anadir_jugador(const string &nombre)
{
    ++nplayers;
    ranking.push_back(mp.insert(make_pair(nombre, Jugador(nplayers))).first);
}

void Cjt_jugadores::eliminar_jugador(const string &nombre)
{
    --nplayers;
    // Inciamos un bucle que sustituye el Jugador actual por el siguiente, des de la posición que eliminamos
    for (int i = mp[nombre].consultar_posicion() - 1; i < nplayers; ++i)
    {
        ranking[i] = ranking[i + 1];
        ranking[i]->second.modificar_posicion(i+1);
    }
    ranking.pop_back();
    mp.erase(nombre);
}

void Cjt_jugadores::sumar_stats(const string &nombre,  int pts, int pg, int pp, int sg, int sp, int jg, int jp)
{
    mp[nombre].sumar_stats(pts, pg, pp, sg, sp, jg, jp);
}

void Cjt_jugadores::sumar_puntos(const string &nombre, int p)
{
    mp[nombre].sumar_puntos(p);
}

string Cjt_jugadores::consultar_nombre(int pos) const
{
    return ranking[pos-1]->first;
}

int Cjt_jugadores::consultar_posicion(const string &nombre)
{
    return mp[nombre].consultar_posicion();
}

int Cjt_jugadores::consultar_puntos(int pos) const
{
    return ranking[pos]->second.consultar_puntos();
}

bool Cjt_jugadores::existe_jugador(const string &nombre) const
{
    return mp.find(nombre) != mp.end();
}

int Cjt_jugadores::consultar_num_jugadores() const
{
    return nplayers;
}

void Cjt_jugadores::listar_ranking() const
{
    for (int i = 0; i < nplayers; ++i) cout << i+1 << " " << ranking[i]->first << " " << ranking[i]->second.consultar_puntos() << endl;
}

void Cjt_jugadores::listar_jugadores() const
{
    cout << nplayers << endl;
    for (It_const_jugador it = mp.begin(); it != mp.end(); it++) it->second.escribir_jugador(it->first);
}

void Cjt_jugadores::escribir_jugador(const string &nombre)
{
    mp[nombre].escribir_jugador(nombre);
}

void Cjt_jugadores::leer_cjt_jugadores()
{
    string name;
    cin >> nplayers;

    ranking = vector<It_jugador>(nplayers);
    for (int i = 0; i < nplayers; ++i)
    {
        cin >> name;
        ranking[i]= mp.insert(make_pair(name, Jugador(i+1))).first;
    }
}

bool Cjt_jugadores::cmp_ranking(const It_jugador &a, const It_jugador &b)
{
    int pts_a = a->second.consultar_puntos();
    int pts_b = b->second.consultar_puntos();
    if(pts_a != pts_b) return pts_a > pts_b;
    return a->second.consultar_posicion() < b->second.consultar_posicion();
}

void Cjt_jugadores::ordenar_ranking()
{
    sort(ranking.begin(), ranking.end(), cmp_ranking);
    for (int i = 0; i < nplayers; i++)
    {
        ranking[i]->second.modificar_posicion(i+1);
    }
}

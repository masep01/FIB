/** @file Circuito.cc
  @brief Código de la clase Circuito
*/
#include "Circuito.hh"

Circuito::Circuito() {}
Circuito::~Circuito() {}

void Circuito::nuevo_torneo(const string &nombre, int categoria)
{
  mc.insert(make_pair(nombre, Torneo(categoria)));
  ++ntorneos;
}

void Circuito::baja_torneo(const string &nombre, Cjt_jugadores &r_global)
{
  if(torneo_jugado(nombre)) mc[nombre].restar_puntos_ultima_edicion(r_global);
  mc.erase(nombre);
  --ntorneos;
  r_global.ordenar_ranking();
}

void Circuito::iniciar_torneo(const string &nombre, const Cjt_jugadores &r_global)
{
  mc[nombre].iniciar_torneo(r_global);
}

void Circuito::finalizar_torneo(string nombre, Cjt_jugadores &r_global, const Cjt_categorias &categ)
{
  mc[nombre].finalizar_torneo(r_global, categ);
}

void Circuito::baja_jugador(const string &nombre, Cjt_jugadores& r_global)
{
  r_global.eliminar_jugador(nombre);

  // Damos de baja al jugador de todos los torneos donde jugó
  for(It_torneo it = mc.begin(); it != mc.end(); ++it) it->second.baja_jugador(nombre);
}

bool Circuito::existe_torneo(const string &nombre) const
{
  return mc.find(nombre) != mc.end();
}

bool Circuito::torneo_jugado(const string &nombre)
{
  return mc[nombre].torneo_jugado();
}

int Circuito::consultar_num_torneos() const
{
  return ntorneos;
}

void Circuito::listar_torneos(Cjt_categorias &categ)
{
  cout << ntorneos << endl;
  for (It_const_torneo it = mc.begin(); it != mc.end(); ++it)
  {
    cout << it->first << " " << categ.consultar_nombre(it->second.consultar_categoria()) << endl;
  }
}

void Circuito::leer_circuito()
{
  string nombre;
  int c;
  cin >> ntorneos;
  for (int i = 0; i < ntorneos; i++)
  {
    cin >> nombre >> c;
    mc.insert(make_pair(nombre, Torneo(c)));
  }
}
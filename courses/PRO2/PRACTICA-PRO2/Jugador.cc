/** @file Jugador.cc
    @brief Código de la clase Jugador
*/
#include "Jugador.hh"

Jugador::Jugador()
{
    puntos = posicion = n_torneos =  p_ganados =  p_perdidos = s_ganados = s_perdidos =  j_ganados =  j_perdidos = 0;
}

Jugador::~Jugador(){}

Jugador::Jugador(int pos)
{
    posicion = pos;
    puntos = n_torneos =  p_ganados =  p_perdidos = s_ganados = s_perdidos =  j_ganados =  j_perdidos = 0;
}

void Jugador::modificar_posicion(int p)
{
    posicion = p;
}

void Jugador::sumar_stats(int pts, int pg, int pp, int sg, int sp, int jg, int jp)
{
    puntos +=pts;
    ++n_torneos;
    p_ganados += pg;
    p_perdidos += pp;
    s_ganados += sg;
    s_perdidos += sp;
    j_ganados += jg;
    j_perdidos += jp;
}

 void Jugador::sumar_puntos(int p)
 {
    puntos += p;
 }

int Jugador::consultar_puntos() const
{
    return puntos;
}

int Jugador::consultar_posicion() const
{
    return posicion;
}

void Jugador::escribir_jugador(const string &nombre) const
{
    cout << nombre << " ";
    cout << "Rk:" << posicion << " Ps:" << puntos << " Ts:" << n_torneos;
    cout << " WM:" << p_ganados << " LM:" << p_perdidos;
    cout << " WS:" << s_ganados << " LS:" << s_perdidos;
    cout << " WG:" << j_ganados << " LG:" << j_perdidos << endl;
}

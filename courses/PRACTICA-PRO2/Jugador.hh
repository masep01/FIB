/** @file Jugador.hh
    @brief Especificación de la clase Jugador
*/

#ifndef JUGADORES_HH
#define JUGADORES_HH

#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

/** @class Jugador
    @brief Representa un jugador
*/

class Jugador {

    private:
        /** @brief Puntos del jugador */
        int puntos;

        /** @brief Posición del jugador */
        int posicion;

        /** @brief Número de torneos disputados del jugador */
        int n_torneos;

        /** @brief Número de partidos ganados del jugador */
        int p_ganados;
        
        /** @brief Número de partido perdidos del jugador */
        int p_perdidos;

        /** @brief Número de sets ganados del jugador */
        int s_ganados;

        /** @brief Número de sets perdidos del jugador */
        int  s_perdidos;

        /** @brief Número de juegos ganados del jugador */
        int j_ganados;

        /** @brief Número de juegos perdidos del jugador */
        int j_perdidos;

    public:
        // Constructoras

        /** @brief Constructora por defecto
            \pre Cierto.
            \post El resultado es un jugador con estadísticas a 0.
        */
        Jugador();

        /** @brief Constructora con posición
            \pre Cierto.
            \post El resultado es un jugador con estadísticas a 0 y posición \em pos.
        */
        Jugador(int pos);

        // Destructora

        /** @brief Destructora por defecto. */
        ~Jugador();

        // Modificadores

        /** @brief Modifica la posición
            \pre Cierto.
            \post El \em p.i. ahora tiene posición \em p.
        */
        void modificar_posicion(int p);

        /** @brief Modifica las estadísticas del jugador
            \pre Cierto.
            \post El \em p.i. ahora tiene añadidos: puntos (pts), partidos ganados (pg), partidos perdidos (pp),
            sets ganados (sg), sets perdidos (sp), juegos ganados (jg) y juegos perdidos (jp) y (+1) torneo disputado.
        */
        void sumar_stats(int pts, int pg, int pp, int sg, int sp, int jg, int jp);

        /** @brief Modifica los puntos
            \pre Cierto.
            \post El \em p.i. ahora tiene posición \em +p.
        */
        void sumar_puntos(int p);

        // Consultores

        /** @brief Consulta los puntos
            \pre Cierto.
            \post El resultado es el número de puntos del \em p.i .
        */
        int consultar_puntos() const;

        /** @brief Consulta la posición
            \pre Cierto.
            \post El resultado es la posición del \em p.i .
        */
        int consultar_posicion() const;

        // Lectura y escriptura

        /** @brief Escribe el p.i.
            \pre Cierto
            \post Se ha escrito en el canal estandar el nombre, la posición en el ranking, los puntos
            y el resto de las estadísticas del \em p.i.
        */
        void escribir_jugador(const string &nombre) const;
};

#endif

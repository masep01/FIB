/** @file Cjt_jugadores.hh
    @brief Especificación de la clase Cjt_jugadores
*/

#ifndef CJT_JUGADORES_HH
#define CJT_JUGADORES_HH

#include "Jugador.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#endif
using namespace std;

/** @class Cjt_jugadores
    @brief Representa un conjunto de jugadores
*/

/** @brief Iterador de un diccionario de <string, Jugador> */
typedef map<string, Jugador>::iterator It_jugador;

/** @brief Iterador constante de un diccionario de <string, Jugador> */
typedef map<string, Jugador>::const_iterator It_const_jugador;

class Cjt_jugadores {

    private:
        /** @brief Diccionario con clave nombre y valor Jugador */
        map<string, Jugador> mp;

        /** @brief Vector contenedor de los nombres jugadores */
        vector<It_jugador> ranking;

        /** @brief Número de jugadores del conjunto */
        int nplayers;

        /** @brief Función comparativa para ordenación
            \pre Cierto.
            \post El resultado es cierto si el jugador al que apunta \em a tiene más puntos que al que apunta \em b, falso en caso contrario.
            En caso de empate, el resultado es cierto si la posición del jugador al que apunta \em a es menor que la del que apunta \em b, falso en caso contrario.
        */
        static bool cmp_ranking(const It_jugador &a, const It_jugador &b);

    public:

        // Constructoras

        /** @brief Constructora por defecto
            \pre Cierto.
            \post El resultado es un conjunto de jugadores vacío.
        */
       Cjt_jugadores();

       /** @brief Constructora con tamaño
            \pre Cierto.
            \post El resultado es un conjunto de jugadores de tamaño \em size.
        */
       Cjt_jugadores(int size);

        // Destructora

        /** @brief Destructora por defecto. */
        ~Cjt_jugadores();

        // Modificadoras

        /** @brief Añade un jugador
            \pre No existe un jugador con identificador \em nombre.
            \post El parámetro implícito se le añade a \em p con estadísticas a 0 y última posición en el ranking.
        */
        void anadir_jugador(const string &nombre);

        /** @brief Elimina un jugador
            \pre Existe un jugador con identificador \em nombre.
            \post Se ha eliminado el jugador con identificador \em nombre del p.i.
        */
        void eliminar_jugador(const string &nombre);

        /** @brief Ordena el ranking
            \pre Cierto.
            \post Se ha ordenado \em ranking por posición decreciente.
        */
        void ordenar_ranking();

        /** @brief Modifica los puntos de un jugador
            \pre Existe un jugador con identificador \em nombre en el \em p.i. .
            \post El jugador con identificador \em nombre ahora tiene añadidos: puntos (pts), partidos ganados (pg), partidos perdidos (pp),
            sets ganados (sg), sets perdidos (sp), juegos ganados (jg) y juegos perdidos (jp).
        */
        void sumar_stats(const string &nombre, int pts, int pg, int pp, int sg, int sp, int jg, int jp);

        /** @brief Modifica los puntos de un jugador
            \pre Existe un jugador con identificador \em nombre en el \em p.i. .
            \post El jugador con identificador \em nombre ahora tiene \em p puntos más.
        */
        void sumar_puntos(const string &nombre, int p);

        // Consultoras

        /** @brief Consulta el nombre de un jugador
            \pre Existe un jugador con posición \em pos en el \em p.i. .
            \post El resultado es el nombre del jugador con posición \em pos.
        */
        string consultar_nombre(int pos) const;

       /** @brief Consulta la posición de un jugador
            \pre Existe un jugador con identificador \em nombre en el \em p.i. .
            \post El resultado es la posición del jugador con identificador \em nombre.
        */
        int consultar_posicion(const string &nombre);

       /** @brief Consulta los puntos de un jugador
            \pre Existe un jugador con posición \em pos en el \em p.i. .
            \post El resultado es el número de puntos del del jugador con posición \em pos.
        */
        int consultar_puntos(int pos) const;

        /** @brief Consulta si existe un jugador de un jugador
            \pre Existe un jugador con identificador \em nombre en el \em p.i. .
            \post El resultado es cierto si el jugador existe en el \em p.i, falso en caso contrario.
        */
        bool existe_jugador(const string &nombre) const;

       /** @brief Consulta el número de jugadores del conjunto
            \pre Existe un jugador con identificador \em nombre en el \em p.i. .
            \post El resultado es el número de jugadores del conjunto.
        */
       int consultar_num_jugadores() const;

        // Lectura y escriptura

        /** @brief Escribe el conjunto de jugadores por posición
            \pre Cierto.
            \post Se listan, por orden creciente de ranking actual, la posición, el nombre y los puntos de cada jugador del circuito.
        */
        void listar_ranking() const;

        /** @brief Escribe el conjunto de jugadores por nombre
            \pre Cierto
            \post Se ha escrito en el canal estandar el número de jugadores. Seguidamente, por orden creciente de identificador, el nombre,
            la posición en el ranking, los puntos y el resto de las estadísticas de cada jugador del \em p.i..
        */
        void listar_jugadores() const;

        /** @brief Escribe un jugador
            \pre Existe un jugador con identificador nombre en el \em p.i. .
            \post Se ha escrito en el canal estandar el nombre, la posición en el ranking,  los puntos
            y el resto de las estadísticas del jugador con identificador \em nombre.
        */
        void escribir_jugador(const string &nombre);

       /** @brief Lee un conjunto de jugadores
            \pre Hay preparados en el canal estandar: el número inicial de jugadores \em P>=0 y una secuencia de P strings
            \post El parámetro implícito pasa a tener \em P  jugadores identificados por nombre y posición.
        */
        void leer_cjt_jugadores();
};

#endif

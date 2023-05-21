/** @file Circuito.hh
    @brief Especificación de la clase Circuito
*/

#ifndef CIRCUITO_HH
#define CIRCUITO_HH

#include "Torneo.hh"
#include "Cjt_jugadores.hh"
#include "Cjt_categorias.hh"

using namespace std;

/** @class Circuito
    @brief Representa un conjunto de torneos
*/

/** @brief Iterador de un diccionario de <string, Torneo> */
typedef map<string, Torneo>::iterator It_torneo;

/** @brief Iterador constante de un diccionario de <string, Torneo> */
typedef map<string, Torneo>::const_iterator It_const_torneo;

class Circuito {

    private:
        /** @brief Almacena los torneos identificados por un string */
        map<string, Torneo> mc;

        /** @brief Número de torneos del circuito*/
        int ntorneos;

    public:

        // Constructoras

        /** @brief Constructora por defecto
            Se ejecuta automáticamente al declarar un circuito.
            \pre Cierto
            \post El resultado es un circuito (conjunto de torneos) vacío.
        */
        Circuito();

        // Destructora

        /** @brief Destructora por defecto. */
        ~Circuito();

        // Modificadoras

        /** @brief Añade un torneo al conjunto
            \pre No existe un torneo con identificador \em nombre , 0 < categoría < Categoría Máxima.
            \post Se ha añadido un torneo al p.i.
        */
        void nuevo_torneo(const string &nombre, int categoria);

        /** @brief Elimina un torneo del conjunto
            \pre Existe un torneo con identificador \em nombre en el p.i.
            \post Se actualiza el ranking después de restar los puntos conseguidos por los jugadores 
            en la última edición del torneo (si se hubiera jugado alguna).
            Se ha ordenado \em r_global por posición decreciente.
        */
        void baja_torneo(const string &nombre, Cjt_jugadores& r_global);

        /** @brief Inicia un torneo
            \pre Existe un torneo con identificador \em nombre en el p.i.
            \post Se ha iniciado el torneo con identificador \em nombre y se imprime el cuadro de emparejamiento.
        */
        void iniciar_torneo(const string &nombre, const Cjt_jugadores& r_global);

       /** @brief Finaliza un torneo
            \pre Existe un torneo con identificador \em nombre en el p.i y ya esta iniciado.
            \post Se actualizan las estadisticas de \em r_global según \em categ después de restar los puntos conseguidos
            por los jugadores en la última edición del torneo (si se hubiera jugado alguna).
        */
        void finalizar_torneo(string nombre, Cjt_jugadores& r_global, const Cjt_categorias& categ);

        /** @brief Se da de baja a un jugador.
            \pre Existe un jugador con identificador \em nombre en \em r_global.
            \post Se elimina el jugador con identificador \em nombre de todos los torneos del circuito y de \em r_global.
        */
        void baja_jugador(const string &nombre, Cjt_jugadores& r_global);

        // Consultoras

        /** @brief Consulta si existe el torneo
            \pre Cierto.
            \post El resultado es cierto si el torneo existe en el \em p.i, falso en caso contrario.
        */
        bool existe_torneo(const string &nombre) const;

        /** @brief Consulta si se ha jugado alguna edición de un torneo.
            \pre Cierto.
            \post El resultado es cierto si el torneo se ha jugado alguna vez en el \em p.i con identificador \em nombre, 
            falso en caso contrario.
        */
        bool torneo_jugado(const string &nombre);

        /** @brief Consulta el número de torneos del circuito
            \pre Cierto.
            \post El resultado es el número de torneos del circuito.
        */
        int consultar_num_torneos() const;

        // Lectura y escriptura

        /** @brief Lista los torneos del conjunto
            \pre Cierto.
            \post Se ha escrito en el canal estándar por orden creciente de identificador, 
            el nombre y la categoría de cada torneo del circuito.
        */
        void listar_torneos(Cjt_categorias &categ);

        /** @brief Operación lectora
            \pre Hay preparados en el canal estandar: el número inicial de torneos T>=0 y una secuencia de T pares <string, int>.
            \post El parámetro implícito pasa a tener T torneos identificados por nombre y categoria.
        */
        void leer_circuito();
};

#endif

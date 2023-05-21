/** @file Torneo.hh
    @brief Especificación de la clase Torneo
*/

#ifndef TORNEO_HH
#define TORNEO_HH

#include "Cjt_categorias.hh"
#include "Cjt_jugadores.hh"
#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#endif

using namespace std;

/** @class Torneo
    @brief Representa un torneo
*/

/** @brief Iterador de un diccionario de <string, int> */
typedef map<string, int>::iterator It_puntos;

/** @brief Iterador constante de un diccionario de <string, int> */
typedef map<string, int>::const_iterator It_const_puntos;

class Torneo {

    private:
        /** @brief Categoría del torneo*/
        int categoria;

        /** @brief Número de inscritos en el torneo*/
        int n_inscritos;

        /** @brief Indica si ha habido alguna edición del torneo */
        bool first_time;

        /** @brief Tupla auxiliar para transimitir estadísticas */
        struct Stats
        {
            int puntos;
            int sets_ganados, sets_perdidos;
            int juegos_ganados, juegos_perdidos;
            int p_ganados, p_perdidos;
        };

        /** @brief Puntos de la edición anterior */
        map<string, int> pts_edicion_ant;

        /** @brief Nombres de los inscritos */
        vector<string> inscritos;

        /** @brief Cuadro de emparejamientos */
        BinTree<int> cuadro;

        /** @brief Operación lectora de jugadores inscritos
            \pre Se ha iniciado el \em p.i. y hay preparados en el canal estándar un entero \em n, y seguidamente \em n enteros que representan sus posiciones en \em r_global.
            \post \em inscritos ahora contiene los nombres de los jugadores inscritos de la edición actual.
        */
        void leer_inscritos (const Cjt_jugadores &r_global);

        /** @brief Genera un árbol con los emparejamientos
            \pre Se han leído los inscritos. \em r  = 1 (jugador ganador teorico con posición 1 en el ranking relativo), \em l = 0 (nivel inicial del árbol).
            \post El resultado es un árbol de enteros con los inscritos emparejados, cuyos nodos representan su posición en el cuadro de emparejamientos.
        */
        BinTree<int> generar_cuadro_emparejamiento(int r, int l);

        /** @brief Escribe el cuadro de emparejamientos
            \pre Se ha generado el cuadro de emparejamientos.
            \post Se escribe por el canal estándar el cuadro de emparejamientos \em a.
        */
        void imprimir_cuadro_emparejamiento(const BinTree<int> &a) const;

        /** @brief Operación lectora de los resultados del torneo
            \pre \em h es la altura maxima del árbol, \em deep  = 0 (incialmente). Hay preparado en el canal estándar para leer un árbol binario de strings en preorden.
            \post El resultado es un árbol binario de strings con los resultados de los partidos.
        */
        BinTree<string> leer_resultados(int deep, int h);

        /** @brief Actualiza el cuadro de emparejamientos según los resultados
            \pre \em a contiene los resultados de los partidos, \em b el emparejamiento inicial y \em categ los puntos correspondientes. \em lvl es 0 incialmente y representa la profundiad.
            \post \em cuadro ahora está modificado con los ganadores según los resultados de \em a. Ahora \em stats contiene las estadísticas recopiladas del desarrollo del torneo
        */
        void desarrollar_torneo(const BinTree<string>& a, BinTree<int> &cuadro, const Cjt_categorias &categ, vector<Stats>& stats, int lvl);

        /** @brief Escribe el cuadro de resultados del torneo
            \pre \em a contiene los resultados de los partidos y \em b los ganadores, \em categ los puntos correspondientes.
            \post Se escribe por el canal estándar el cuadro oficial de resultados.
        */
        void imprimir_cuadro_resultados(const BinTree<string>& a, const BinTree<int> &b, const Cjt_jugadores &r) const;

        /** @brief Actualiza las estadísticas y escribe los puntos obtenidos por los participantes.
            \pre Cierto.
            \post Se actualizan todas las estadísticas de los participantes de \em r_global según \em stats, \em pts_edicion_ant ahora contiene
            los puntos de la edición actual, \em first_time = true y se escriben por el canal estandar los puntos obtenidos por los jugadores en orden inicial de inscripción.
        */
        void procesar_ranking_relativo(Cjt_jugadores &r_global, vector<Stats>& stats);

        /** @brief Procesa un partido en forma de string
          
            Esta operación trata el string que contiene el partido como un vector. 
            Seleccionando así los juegos de cada jugador y calculando posteriormente cuántos sets gana cada uno.
            Por último se añaden las estadísticas recaudadas al vector de estadísticas.

            \pre \em match es el resultado del partido, \em a y \em b son las posiciones en el ranking relativo de los contrincantes de un partido \em a vs. \em b.
            \post El resultado es la posición del ganador en el ranking relativo y \em stats se ha actualizado con los resultados del partido (sets, juegos, partidos...).
        */
        int procesar_partido(const string &match, const int &a, const int &b, vector<Stats>& stats);

    public:
        // Constructoras
        /** @brief Constructora por defecto
            \pre Cierto
            \post El resultado es un torneo sin jugadores, con \em categoria 0 y \em first_time = false
        */
        Torneo();

        /** @brief Constructora por categoría
            \pre c > 0
            \post El resultado es un torneo con categoría \em c y \em first_time = false
        */
        Torneo(int c);

        // Destructora

        /** @brief Destructora por defecto. */
        ~Torneo();

        // Modificadoras

        /** @brief Inicia el torneo
            \pre Cierto.
            \post Se ha iniciado \em p.i. , escrito por el canal estándar el \em cuadro de emparejamientos 
            (este ahora contiene los partidos a disputar) y \em inscritos ahora contiene los jugadores inscritos al torneo.
        */
        void iniciar_torneo(const Cjt_jugadores& r_global);

        /** @brief Finaliza el torneo
            \pre El \em p.i. ya está iniciado.
            \post Se finaliza el \em p.i. así actualizando \em r_global  con las estadísticas generadas por el desarrollo del torneo
            después de restar los puntos conseguidos por los jugadores en la última edición del torneo (si se hubiera jugado alguna) y ordenado el ranking por posición. 
            Se ha escrito por el canal estándar el cuadro oficial de resultados y listado los puntos ganados por los inscritos en orden de inscripción.
        */
        void finalizar_torneo(Cjt_jugadores& r_global, const Cjt_categorias& categ);

        /** @brief Resta puntos conseguidos por los jugadores en la última edición del torneo.
            \pre Se ha jugado como mínimo una edición del torneo ( \em first_time = true).
            \post Se han restado los puntos conseguidos por los jugadores en la última edición del torneo en \em r .
        */
        void restar_puntos_ultima_edicion(Cjt_jugadores &r);

        /** @brief Da de baja a un jugador del torneo
            \pre No se ha iniciado el torneo.
            \post Se ha eliminado a un jugador con identificador \em nombre, si lo existe, de \em pts_edicion_actual.
        */
        void baja_jugador(const string &nombre);

        // Consultoras

        /** @brief Consultora de categoría
            \pre Cierto.
            \post El resultado es la \em categoria del \em p.i. .
        */
        int consultar_categoria() const;

        /** @brief Consulta si se ha jugado alguna edición del torneo
            \pre Cierto.
            \post El resultado es cierto si el torneo se ha jugado alguna vez en el p.i con identificador \em nombre, falso en caso contrario.
        */
        bool torneo_jugado() const;
};

#endif

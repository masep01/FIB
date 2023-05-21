/** @file Cjt_categorias.hh
    @brief Especificación de la clase Cjt_categorias
*/

#ifndef CJT_CATEGORIAS_HH
#define CJT_CATEGORIAS_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <vector>
#endif

using namespace std;

/** @class Cjt_categorias
    @brief Representa un conjunto de categorías
*/

/** @brief Definición de Matriz de números enteros */
typedef vector<vector<int>> Matriz;

class Cjt_categorias {

    private:
        /** @brief Vector con los nombres de las categorías */
       vector<string> vcat;

        /** @brief Matriz de enteros con los puntos
        \em C (categorias) x \em K (niveles) */
        Matriz m_pts;

        /** @brief Categoría máxima */
        int max_cat;

        /** @brief Número de niveles */
        int niveles;

    public:
        // Constructoras

        /** @brief Constructora por defecto
            \pre Cierto.
            \post El resultado es un conjuto de categorías.
        */
        Cjt_categorias();

        // Destructora

        /** @brief Destructora por defecto*/
        ~Cjt_categorias();

        // Modificadoras

        // Consultoras

        /** @brief Consulta la categoria máxima
            \pre Cierto.
            \post El resultado es el valor numérico de la categoría máxima.
        */
        int categoria_maxima() const;

        /** @brief Consulta los puntos por categoría y nivel
            \pre Cierto.
            \post El resultado son los puntos correspondientes según nivel y categoría.
        */
        int consultar_puntos(int cat, int nivel) const;

        /** @brief Consulta el nombre de la categoría
            \pre Cierto.
            \post El resultado es el nombre de la categoría \em c.
        */
        string consultar_nombre(int c) const;

        // Lectura y escriptura

        /** @brief Escribe las categorías
            \pre Cierto.
            \post Se ha escrito en el canal estándar por orden creciente de identificador, el nombre y
            la tabla de puntos por niveles (en orden creciente de nivel) de cada categoría del \em p.i.
        */
        void listar_categorias() const;

        /** @brief Lee un conjunto de categorías
            \pre Hay preparados en el canal estandar: el número de categorías \em C, el número maximo de niveles \em K,
            una secuencia de \em C strings. Seguidamente, \em C x \em K enteros (>= 0).
            \post El parámetro implícito pasa a tener \em C categorias identificadas por nombre con \em K máximos niveles y 
            su matriz de puntos correspondiente de CxK enteros.
        */
        void leer_cjt_categorias();
};
#endif

/** @mainpage
<b>Práctica Primavera 2022 (Q2) PRO2</b>

Elaborada por: <em>Josep Antoni Martínez Garcia</em>, Grupo 33

Documentación completa de la práctica:

El programa principal se encuentra en el módulo \em main.cc . La práctica cuenta con cinco módulos:
    - Circuito.hh
    - Torneo.hh
    - Cjt_jugadores.hh
    - Jugador.hh
    - Cjt_categorias.hh

El objetivo de la práctica es llevar a cabo la construcción un programa capaz de gestionar un circuito de Torneos de Tenis.
El cual vaya lidiando con un ranking de jugadores y sus respectivas estadísticas. El programa admite diversos
comandos que realizan diversas tareas relacionadas con los de torneos y jugadores del circuito.

*/

/** @file main.cc
    @brief Programa principal

    El programa se estructura en dos bloques. El primero se encarga de declarar y leer los objetos a tratar. El segundo se constituye de un bucle
    que procesa los comandos admitidos por cadenas de texto, ya sea mediante su versión completa como la abreviada.
*/

#include "Circuito.hh"
#include "Cjt_jugadores.hh"
#include "Cjt_categorias.hh"

int main() {

    // Declaración y lectura del conjunto de categorías
    Cjt_categorias categ;
    categ.leer_cjt_categorias();

    // Declaración y lectura del conjunto de torneos
    Circuito c;
    c.leer_circuito();

    // Declaración y lectura del conjunto de jugadores
    Cjt_jugadores ranking;
    ranking.leer_cjt_jugadores();

    string op;
    cin >> op;

    //Tratamiento de los comandos del programa
    while(op != "fin") {
        if(op == "nuevo_jugador" or op == "nj"){
            string n;
            cin >> n;
            cout << "#" << op << " " << n << endl;

            if(ranking.existe_jugador(n)) cout << "error: ya existe un jugador con ese nombre" << endl;
            else {
                ranking.anadir_jugador(n);
                cout << ranking.consultar_num_jugadores() << endl;
            }
        }
        else if (op == "nuevo_torneo" or op == "nt"){
            int cat;
            string nombre;
            cin >> nombre >> cat;
            cout << "#" << op << " " << nombre << " " << cat << endl;

            if(cat < 1 or cat > categ.categoria_maxima()) cout << "error: la categoria no existe" << endl;
            else if(c.existe_torneo(nombre)) cout << "error: ya existe un torneo con ese nombre" << endl;
            else{
                c.nuevo_torneo(nombre, cat);
                cout << c.consultar_num_torneos() << endl;
            }
        }
        else if (op == "baja_jugador" or op == "bj"){
            string n;
            cin >> n;
            cout << "#" << op << " " << n << endl;

            if(not ranking.existe_jugador(n)) cout << "error: el jugador no existe" << endl;
            else {
                c.baja_jugador(n, ranking);
                cout << ranking.consultar_num_jugadores() << endl;
            }
        }
        else if (op == "baja_torneo" or op == "bt"){
            string nombre;
            cin >> nombre;
            cout << "#" << op << " " << nombre << endl;

            if(not c.existe_torneo(nombre)) cout << "error: el torneo no existe" << endl;
            else{
                c.baja_torneo(nombre, ranking);
                cout << c.consultar_num_torneos() << endl;
            }
        }
        else if (op == "iniciar_torneo" or op == "it"){
            string n;
            cin >> n;
            cout << "#" << op << " " << n << endl;

            c.iniciar_torneo(n, ranking);
        }
        else if (op == "finalizar_torneo" or op == "ft"){
            string n;
            cin >> n;
            cout << "#" << op << " " << n << endl;

            c.finalizar_torneo(n, ranking, categ);
        }
        else if (op == "listar_ranking" or op == "lr") {
            cout << "#" << op << endl;
            ranking.listar_ranking();
        }
        else if (op == "listar_jugadores" or op == "lj"){
            cout << "#" << op << endl;
            ranking.listar_jugadores();
        }
        else if (op == "consultar_jugador" or op == "cj"){
            string n;
            cin >> n;
            cout << "#" << op << " " << n << endl;

            if(ranking.existe_jugador(n)) ranking.escribir_jugador(n);
            else cout << "error: el jugador no existe" << endl;
        }
        else if (op == "listar_torneos" or op == "lt"){
            cout << "#" << op << endl;
            c.listar_torneos(categ);
        }
        else if (op == "listar_categorias" or op == "lc"){
            cout << "#" << op << endl;
            categ.listar_categorias();
        }
        cin >> op;
    }
}

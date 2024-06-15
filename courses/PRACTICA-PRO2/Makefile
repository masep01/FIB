OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Circuito.o Torneo.o Cjt_jugadores.o Jugador.o Cjt_categorias.o
	g++ -o program.exe *.o 

Circuito.o: Circuito.cc Torneo.hh Cjt_jugadores.hh Cjt_categorias.hh
	g++ -c Circuito.cc $(OPCIONS)

Torneo.o: Torneo.cc Cjt_jugadores.hh Cjt_categorias.hh BinTree.hh
	g++ -c Torneo.cc $(OPCIONS)

Cjt_jugadores.o: Cjt_jugadores.cc Cjt_jugadores.hh Jugador.hh
	g++ -c Cjt_jugadores.cc $(OPCIONS)

Jugador.o: Jugador.cc Jugador.hh
	g++ -c Jugador.cc $(OPCIONS)

Cjt_categorias.o: Cjt_categorias.cc Cjt_categorias.hh
	g++ -c Cjt_categorias.cc $(OPCIONS)

program.o: program.cc Circuito.hh Cjt_jugadores.hh Cjt_categorias.hh
	g++ -c program.cc $(OPCIONS)

practica.tar: html.zip Circuito.cc Circuito.hh Cjt_categorias.cc Cjt_categorias.hh Cjt_jugadores.hh Cjt_jugadores.cc Jugador.hh Makefile program.cc Torneo.cc Torneo.hh Jugador.cc
	tar -cvf practica.tar html.zip Circuito.cc Circuito.hh Cjt_categorias.cc Cjt_categorias.hh Cjt_jugadores.hh Cjt_jugadores.cc Jugador.hh Makefile program.cc Torneo.cc Torneo.hh Jugador.cc
	
clean:
	rm -f *.o
	rm -f *.exe
\*------------------ PROJECTE SLIDER ------------------*/

# Autors: 	Oriol Roca Núñez i Josep Martinez Garcia
# Grup:	H
# Data: 	04/01/2023

# Descripció:
	
Es tracta d'un videojoc implementat a la PIC18F45K22. 
Es basa en el moviment d'un personatge amb l'objectiu 
d'aconseguir un total 500 punts abans que passin 60
segons. Hi han obstacles com murs que es van apropant
de dreta a esquerra els quals t'eliminen instantàniament
al tocar-los. D'altra banda tenim 2 tipus d'objectes:
els fantasmes que resten una vida i les monedes, 
que sumen 75 punts. 

Estadístiques inicials:
	- 0 punts
	- 3 vides
	- 0 segons

Botons:
	- Up
	- Down
	- Left
	- Right

	- + dificultat
	- - dificultat
	- Select

Si s'augmenta la dificultat, s'incrementa la velocitat de 
moviment del fantasma. Altrament, es redueix.
Podem moure el personatge mitjançant els botos o fent ús
del terminal virtual.

# Problemes de desenvolupament

Encara no sabem el perquè, però a vegades, es printen "taques" 
a la pantalla. Així printant i esborrant alguns pixels dels gràfics 
mostrats del joc. Suposem que ve donat per algun tipus d'error 
amb el marcador, el qual es torna a pintar poc a poc a altres zones 
de la pantalla.
\*------------------------------------------------------------------*/
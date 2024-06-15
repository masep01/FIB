#include <iostream>
#include <vector>
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"
using namespace std;


void update(Cjt_estudiants& v1, const Cjt_estudiants& v2) 
{

    for(int i = 1; i <= v1.mida(); ++i) {
        if(v1.consultar_iessim(i).te_nota()) {
            if(v2.consultar_iessim(i).te_nota() and 
                v1.consultar_iessim(i).consultar_nota() < v2.consultar_iessim(i).consultar_nota()) {

                    Estudiant e(v1.consultar_iessim(i).consultar_DNI());
                    e.afegir_nota(v2.consultar_iessim(i).consultar_nota());
                    v1.modificar_iessim(i, e);
            }  
        }
        else if(v2.consultar_iessim(i).te_nota()){

            Estudiant e(v1.consultar_iessim(i).consultar_DNI());
            e.afegir_nota(v2.consultar_iessim(i).consultar_nota());
            v1.modificar_iessim(i, e);
        }
    }
    
}


int main()
{
    //Declaracions
    Cjt_estudiants first_v, sec_v;

    //Llegim el primer conjunt d'estudiants
    first_v.llegir();

    //Llegim el segon conjunt d'estudiants
    sec_v.llegir();

    //Actualitzem el primer conjunt d'estudiants

    update(first_v, sec_v);

    //Escrivim a l'output el primer conjunt actualitzat
    first_v.escriure();


}
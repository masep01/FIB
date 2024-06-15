#include <iostream>
#include <vector>
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"
using namespace std;


double redondear(double r)
{  
  return int(10.*(r + 0.05)) / 10.0;
} 

void opt_4(Cjt_estudiants& v){
    for (int i = 1; i <= v.mida(); i++)
    {
        
        Estudiant e = v.consultar_iessim(i);
        if(e.te_nota()){
            double nota = redondear(e.consultar_nota());
            e.modificar_nota(nota);
            v.modificar_estudiant(e);
        }
        
    }
    
}

int main()
{
    Cjt_estudiants v;
    v.llegir();

    int menu;
    cin >> menu;
    while(menu != -6){

        if(menu == -1) {
            Estudiant e;
            e.llegir();
            if(not v.existeix_estudiant(e.consultar_DNI())){ 
                if(v.mida() < v.mida_maxima()) v.afegir_estudiant(e);
                else cout << "el conjunto esta lleno" << endl << endl;
            }
            else cout << "el estudiante " << e.consultar_DNI() << " ya estaba" << endl << endl;
            
        }
        else if(menu == -2){
            int dni;
            cin >> dni;
            if(v.existeix_estudiant(dni)){
                if(v.consultar_estudiant(dni).te_nota()) {
                    cout << "el estudiante " << dni << " tiene nota " << v.consultar_estudiant(dni).consultar_nota() << endl;
                }
                else cout << "el estudiante " << dni << " no tiene nota" << endl;
            }
            else cout << "el estudiante " << dni << " no esta" << endl;
            cout << endl;
            
        }
        else if(menu == -3){
            Estudiant e1;
            e1.llegir();
            if(v.existeix_estudiant(e1.consultar_DNI())) v.modificar_estudiant(e1);
            else cout << "el estudiante " << e1.consultar_DNI() << " no esta" << endl << endl;
            
        }
        else if(menu == -4) opt_4(v);
        else if(menu == -5) {
            v.escriure();
            cout << endl;
        }
        
        cin >> menu;
    }
}
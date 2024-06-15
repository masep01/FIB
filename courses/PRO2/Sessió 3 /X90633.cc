#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
  
    b = false;
    int dni = est.consultar_DNI();

    int i = cerca_dicot(vest, 0, nest-1, dni);
    if(dni == vest[i].consultar_DNI()) b = true;
    else{
        int j = nest-1;
        bool found = false;
        while(not found and j >= i){
            if(dni > vest[j].consultar_DNI()) found = true;
            else{
                vest[j+1] = vest[j];
                --j;
            }
        }
        vest[j+1] = est;
        ++nest;

        if(est.te_nota()) {
            ++nest_amb_nota;
            suma_notes += est.consultar_nota();
        }
    }

}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
{
    b = false;
    int i = cerca_dicot(vest, 0, nest-1, dni);
    if(i < nest and dni == vest[i].consultar_DNI()) {
        b = true;
        if(vest[i].te_nota()) {
            suma_notes -= vest[i].consultar_nota();
            --nest_amb_nota;
        }
        for(int j = i; j < nest-1; ++j) vest[j] = vest[j+1];
        --nest;
    }
}

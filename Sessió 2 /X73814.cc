#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

vector<Estudiant> simplificar(const vector<Estudiant>& vec, int s_vec){
    vector<Estudiant> sortida(s_vec);
    
    int dni = vec[0].consultar_DNI();
    Estudiant e(dni);
    sortida[0] = e;

    if(vec[0].te_nota()) sortida[0].afegir_nota(vec[0].consultar_nota());

    int j = 0;

    for(int i = 1; i < vec.size(); ++i){
        if(vec[i].consultar_DNI() != dni){
            ++j;
            dni = vec[i].consultar_DNI();
            Estudiant e2(dni);
            sortida[j] = e2;
            if(vec[i].te_nota()) sortida[j].afegir_nota(vec[i].consultar_nota());
        }
        else if(vec[i].te_nota()) {
            if(sortida[j].te_nota()){
                if(sortida[j].consultar_nota() < vec[i].consultar_nota()) sortida[j].modificar_nota(vec[i].consultar_nota());
            }
            else sortida[j].afegir_nota(vec[i].consultar_nota());
        }
    }
    
    return sortida;
}

vector<Estudiant> read_vec(int n){
    vector<Estudiant> vec(n);
    for(int i = 0; i < n; ++i) vec[i].llegir();
    return vec;
}

void print_vec(const vector<Estudiant>& sortida){
    for(int k = 0; k < sortida.size(); ++k) sortida[k].escriure();
}

int main(){
    int n;
    cin >> n;
    
    vector<Estudiant> vec = read_vec(n);
  
    int size_out = 1;
    for(int j = 1; j < n; ++j){
        if(vec[j].consultar_DNI() != vec[j-1].consultar_DNI()) ++size_out;
    }

    vector<Estudiant> sortida = simplificar(vec,size_out);
    print_vec(sortida);
    
}

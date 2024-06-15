#include <iostream>
#include <vector>
#include <algorithm>
#include "Estudiant.hh"
using namespace std;

typedef vector<double> Vector;

Vector read_vec(int n){
    Vector vec(n);
    for(int i = 0; i < n; ++i) cin >> vec[i];   
    return vec;
}

void print_vec(const vector<Estudiant>& vec){
    for(int k = 0; k < vec.size(); ++k) vec[k].escriure(); 
}

vector<Estudiant> mitjanes(const Vector& selected_assigs, int n_est, int assig, int sel_assig){
   
    vector<Estudiant> vec(n_est);

    for(int i = 0; i < n_est; ++i){
        int dni;
        cin >> dni;

        double mitjana = 0;

        for(int j = 1; j <= assig; ++j){
            double nota;
            cin >> nota;
            
            bool found = false;
            int index = 0;
            while(not found and index < sel_assig){

                if(j == selected_assigs[index]) found = true;
                else ++index;
            }
            if(found) mitjana += nota;
            
        }
        mitjana /= sel_assig;

        Estudiant e(dni);
        e.afegir_nota(mitjana);
        vec[i] = e;
    }
    return vec;
}

bool compare(Estudiant a, Estudiant b){
    if(a.consultar_nota() != b.consultar_nota()) return a.consultar_nota() > b.consultar_nota();
    return a.consultar_DNI() < b.consultar_DNI();
}

int main()
{
    int n_est, assig, sel_assig;
    cin >> n_est >> assig >> sel_assig;

    Vector selected_assigs = read_vec(sel_assig); //Vector d'assignatures seleccionades

    vector<Estudiant> vec = mitjanes(selected_assigs, n_est, assig, sel_assig);
    sort(vec.begin(), vec.end(), compare); //Ordenacio decreixent

    print_vec(vec);                        //Escriure a output

}
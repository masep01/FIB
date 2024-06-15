#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

typedef vector<double> Vector;

Vector read_vec(int n){
    Vector vec(n);
    for(int i = 0; i < n; ++i) cin >> vec[i];   
    return vec;
}

void mitjanes(const Vector& selected_assigs, int n_est, int assig, int sel_assig){
   
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
        cout << dni << " " << mitjana/sel_assig << endl;
    }
    
    
}

int main()
{
    int n_est, assig, sel_assig;
    cin >> n_est >> assig >> sel_assig;

    Vector selected_assigs = read_vec(sel_assig); //Vector d'assignatures seleccionades
    
    mitjanes(selected_assigs, n_est, assig, sel_assig);

}
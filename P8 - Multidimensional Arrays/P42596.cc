#include <iostream>
#include <vector>

using namespace std;


typedef vector<vector<int> > Matriu;

void min_max(const Matriu& mat, int& minim, int& maxim){
    
    int files = mat.size();
    int columnes = mat[0].size();
    
    maxim = mat[0][0];
    minim = mat[0][0];
    
    for (int i = 0; i < files; ++i){
            for (int j = 0; j < columnes; ++j){
                if (mat[i][j] > maxim) maxim = mat[i][j];
                else if (mat[i][j] < minim) minim = mat[i][j];
            }
        }
    
}

int main(){
    
    int files, columnes;
    int posicio = 1, pos = 0;
    
   
    int dif = 0, dif_aux = 0;
    
    while (cin >> files >> columnes) {
    
        Matriu matriu(files,vector<int>(columnes));
        
        for (int i = 0; i < files; ++i){
            for (int j = 0; j < columnes; ++j) cin >> matriu[i][j];
        }
        
        int minim = 0, maxim = 0;
        
        min_max(matriu, minim, maxim);
        
        if (maxim > minim) dif_aux = maxim - minim;
        else dif_aux = minim - maxim;
        ++pos;
        
        if (dif_aux > dif){ 
            dif = dif_aux;
            posicio = pos;
        }
    }
    
    cout << "la diferencia maxima es " << dif << endl;
    cout << "la primera matriu amb aquesta diferencia es la " << posicio << endl;
}    

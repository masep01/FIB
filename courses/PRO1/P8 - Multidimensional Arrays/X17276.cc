#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <vector<int> > Matriu;

bool dig_creixent(const Matriu& matriu, int fil, int col){

    int f = matriu.size();
    int c = matriu[0].size();

    int fila = fil;
    int columna = col;

    // Primera diagonal

        int ultim = matriu[fila][columna];
        
        --fila;
        --columna;

        while (fila >= 0  and columna >= 0){
           if (ultim < matriu[fila][columna]) ultim = matriu[fila][columna];
            else return false;
            --fila;
            --columna;
            
        }
        

    fila = fil;
    columna = col;

    // Segona diagonal

        ultim = matriu[fila][columna];
        
        --fila;
        ++columna;

        while (fila >= 0  and columna < c){
            if (ultim < matriu[fila][columna]) ultim = matriu[fila][columna];
            else return false;

            --fila;
            ++columna;
        
        }

        fila = fil;
        columna = col;

    // Tercera diagonal

        ultim = matriu[fila][columna];
        
        ++fila;
        --columna;

        while (fila < f  and columna >= 0){
            if (ultim < matriu[fila][columna]) ultim = matriu[fila][columna];
            else return false;
            ++fila;
            --columna;
            
        }

        fila = fil;
        columna = col;

    // Quarta diagonal
        
        ultim = matriu[fila][columna];

        ++fila;
        ++columna;

        while (fila < f and columna < c){
            if (ultim < matriu[fila][columna]) ultim = matriu[fila][columna];
            else return false;
                
            ++fila;
            ++columna;
            
        }
        
    return true;
    
}


int main(){

    int files, columnes;
    while (cin >> files >> columnes) {
    
        Matriu matriu(files,vector<int>(columnes));
    
        for (int i = 0; i < files; ++i){
            for (int j = 0; j < columnes; ++j) cin >> matriu[i][j];
        }

        int ini_f, ini_c;
        cin >> ini_f >> ini_c;

        if(dig_creixent(matriu,ini_f, ini_c)) cout << "si" << endl;
        else cout << "no" << endl;

    }
}
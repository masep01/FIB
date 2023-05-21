#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > Matriu;

void transposa(Matriu& m){
    
    int n = m.size();
    int aux = 0;
    
    for (int i = 0; i < n; ++i) {
        
        for (int j = 0; j < i; ++j){
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
    }
    
}

int main (){
    
    int files, columnes;
    cin >> files >> columnes;
    
    Matriu matriu(files,vector<int>(columnes));
   
    for (int i = 0; i < files; ++i){
        for (int j = 0; j < columnes; ++j) cin >> matriu[i][j];
    }
    
    transposa(matriu);
    cout << endl;
    
    for (int k = 0; k < files; ++k){
        
        for (int l = 0; l < columnes; ++l) cout << " " << matriu[k][l];
        cout << endl;
    }
    
}

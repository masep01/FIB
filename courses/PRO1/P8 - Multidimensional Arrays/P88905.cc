#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > Matriu;

Matriu producte(const Matriu& a, const Matriu& b){
    
    int files = a.size();
    int columnes = b[0].size();
    
    Matriu res(files,vector<int>(columnes));
    for (int i = 0; i < files; ++i){
        
        for(int j = 0; j < columnes; ++j) {
            
            for(int k = 0; k < a[0].size(); ++k){
                
                res[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }
    return res;
    
}


int main(){
    
    int files, columnes;
    cin >> files >> columnes;
    
    Matriu matriu1(files,vector<int>(columnes));
    Matriu matriu2(files,vector<int>(columnes));
   
    for (int i = 0; i < files; ++i){
        for (int j = 0; j < columnes; ++j) cin >> matriu1[i][j];
    }
    
    cin >> files >> columnes;
    
    for (int r = 0; r < files; ++r){
        for (int u = 0; u < columnes; ++u) cin >> matriu2[r][u];
    }
    
    Matriu matriu3 = producte(matriu1,matriu2);
    cout << endl;
    
    for (int k = 0; k < matriu3.size(); ++k){
        
        for (int l = 0; l < matriu3[0].size(); ++l) cout << " " << matriu3[k][l];
        cout << endl;
    }
}

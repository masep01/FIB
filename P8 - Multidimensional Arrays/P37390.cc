#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > Matriu;

Matriu producte(const Matriu& a, const Matriu& b){
    
    int n = a.size();
    Matriu res(n,vector<int>(n));
    for (int i = 0; i < n; ++i){
        
        for(int j = 0; j < n; ++j) {
            
            for(int k = 0; k < n; ++k){
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
    
    for (int r = 0; r < files; ++r){
        for (int u = 0; u < columnes; ++u) cin >> matriu2[r][u];
    }
    
    Matriu matriu3 = producte(matriu1,matriu2);
    cout << endl;
    
    for (int k = 0; k < files; ++k){
        
        for (int l = 0; l < columnes; ++l) cout << " " << matriu3[k][l];
        cout << endl;
    }
}

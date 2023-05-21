#include <iostream>	
#include <cmath>
using namespace std;

void info_sequencia(int& suma, int& ultim) {
    int true_ultim;
    ultim = 0;
    suma = 0;
    cin >> true_ultim;
    while (true_ultim != 0) {
        
        suma = suma + ultim;
        ultim = true_ultim;
        
        cin >> true_ultim;
    }
    
}


int main() {
    
    int suma = 0, ultim = 0;
    int res = 1;
    int aux_s = 0, aux_u = 0;
    
    info_sequencia(suma, ultim);
    
    info_sequencia (aux_s, aux_u);
    
    while (not (aux_s == 0 and aux_u == 0)) {
        if (suma == aux_s and ultim == aux_u) ++res;
        info_sequencia(aux_s, aux_u);
        
    }
        
    cout << res << endl; 
}

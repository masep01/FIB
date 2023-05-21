#include <iostream>
using namespace std;

bool primer(int n) {
    bool pr = false;
    int i = 0;
    
    if (n == 1 or n == 0) pr = true;
    else {
        pr = false;
        i = 2;
        while (i*i <= n and not pr){
            if (n%i == 0) pr = true;
            else i = i + 1;
        }
        
    }
    return not pr;
}


int sum_dig(int n){
    int aux = 0;
    
    while (n > 9) {
        aux = aux + n%10;
        n /= 10;
    }
    
    return aux + n;
}

bool es_primer_perfecte(int n) {
 
    if (primer(n)){
        
        if (n < 10) return primer(n);
        else {
            int aux = sum_dig(n);
            
            if (primer(aux)) return es_primer_perfecte(aux);
            else return false;
        }
        
    }
    else return false;
}

int main() {
    int n;
    cin >> n;
    
    
    if (es_primer_perfecte(n)) cout << "true" << endl;
    else cout << "false" << endl;
    
    
}
    

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

int next_prim (int n) {
    
    int aux;
    
    if (n%2 == 0) aux = n + 1;
    else aux = n + 2;
    
    while (not primer(aux)){ 
        aux = aux + 2;
        
    }
    return aux;
}


int main() {
    int n;
    
    cin >> n;
    
    int aux = n;
    while (primer(n)) {
        aux = next_prim(n);
        cout << aux << endl;
        cin >> n;
    }
    
}

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    int n, aux, prod = 1;
    
    while (cin >> n) {

        if (n < 10) cout << "El producte dels digits de " << n << " es " << n << "." << endl;
        else {
            
            while (n >= 10) {
                aux = n;
                
                while (n != 0) {
                    
                    prod = prod * (n%10);
                    n = n/10;
                }
                
                cout << "El producte dels digits de " << aux << " es " << prod << "." << endl;
                
                n = prod;
                prod = 1;
            }
            
            }
            
         cout << "----------" << endl;
    }
} 

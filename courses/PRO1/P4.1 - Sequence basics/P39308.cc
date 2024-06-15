#include <iostream>
#include <cmath>
using namespace std;

int main() {

     int n=0, d = 1;
    
     while (cin >> n){
         
        
        cout << "divisors de " << n << ":";   
        d=1;
        while (d <= sqrt(n)){
                
            if (n%d == 0) cout << " " << d;
            ++d;
        }
        
        for (int i = sqrt(n); i > 0; --i) {
                
            if ((n % i == 0) and (i != n/i)) cout << " " << n/i;
                
            
        }
        
        cout << endl;  
    
    }
    
} 

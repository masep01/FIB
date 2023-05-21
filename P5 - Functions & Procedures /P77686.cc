#include <iostream>	
#include <cmath>
using namespace std;

bool es_capicua(int n) { 

    int num_rev = 0, num_inicial = n, dig = 0;

    while (n!=0) {

        dig = n%10;
        n = n/10;

        num_rev = dig + (num_rev * 10);

    }
    
    if (num_inicial == num_rev) return true;
    else return false;
    

}

int main () {

    int n; 
    cin >> n;

    if (es_capicua(n)) cout << "true" << endl;
    else cout << "false" << endl;
  
}
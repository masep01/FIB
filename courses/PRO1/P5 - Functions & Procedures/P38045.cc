#include <iostream>	
#include <cmath>
using namespace std;


void bromita(int& q, double& arrel) {
    
    q = q*q;
    arrel = sqrt(arrel);
}

int main () {
    cout.setf(ios::fixed);
    cout.precision(6);
    int a;
    
    while (cin >> a){
        int q = a;
        double arrel = a;
        
        bromita(q, arrel);
        cout << q;
        
        
        cout << " " << arrel << endl;
    }  
}

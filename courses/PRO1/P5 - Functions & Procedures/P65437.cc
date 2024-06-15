#include <iostream>	
using namespace std;


void swap2(int& a, int& b){
    
    int aux;
    aux = a;
    a = b;
    b = aux;

    
}

int main () {
 int a, b;
 
 cin >> a >> b;
 
    swap2(a, b);
    cout << a << " " << b << endl;
        
}

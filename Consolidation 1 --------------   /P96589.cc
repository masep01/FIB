#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    char c;
    
    cin >> c;
    
    if ((c >= 48) and (c <= 57)) cout << "digit" << endl; 
    else if (((c >= 65 ) and (c <= 90)) or ((c >= 97) and (c <= 122))) cout << "lletra" << endl; 
    else cout << "res" << endl; 
    
        
} 


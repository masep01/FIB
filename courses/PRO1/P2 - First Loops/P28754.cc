#include <iostream>
using namespace std;


int main () {
    
    int n;
    
    cin >> n;
    
    while (n/2 != 0) {
        
        cout << n%2;
        n = n/2;
    }
    
    cout << n << endl;
}

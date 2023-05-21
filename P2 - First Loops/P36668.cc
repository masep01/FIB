#include <iostream>
using namespace std;


int main () {
    
    int n, r=0;
    
    cin >> n;
    
    while (n!=0) {
        
        r = r + n * n;
        
        n = n - 1;
    }
    cout << r << endl;
    
}

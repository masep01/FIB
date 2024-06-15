#include <iostream>
using namespace std;

int main() {

    int  b, n, x;
    
 
    while (cin >> b >> n) {
        int c=0;
        x = n;
        
        while (x != 0) {
            
            x = x/b;
            c = c + 1;
            
        }
        
        cout << c << endl;
    }
    
}

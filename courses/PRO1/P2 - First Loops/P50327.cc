#include <iostream>
using namespace std;


int main () {
    
    int n;
    
    cin >> n;
    
    while (n > 9){
        
        cout << n%10;
        n = n/10;
    }
    
    cout << n << endl;
}

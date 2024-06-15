#include <iostream>
using namespace std;

int main() {

    int n;
    
    cin >> n;
    
    for (int j = 1; j <= n; ++j){
        
        for (int i = n; i > j; --i){
            cout << "+";
            
        }
        cout << "/";
    
        for (int u = 1; u < j; ++u) cout << "*";
        cout << endl;
        
    }
    
}
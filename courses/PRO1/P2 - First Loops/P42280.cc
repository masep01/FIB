#include <iostream>
using namespace std;

int main() {

    int  f, c, r = 0;
    char n;
    cin >> f >> c;
    
    for (int i = 1; i <= f; ++i) {
        
        for (int j = 1; j <= c; ++j){
            
            cin >> n;
            
            r = r + n - '0';
        } 
    }
    
    cout << r << endl;
}

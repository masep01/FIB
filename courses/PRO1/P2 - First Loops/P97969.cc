#include <iostream>
using namespace std;


int main () {
    
    char c;
    int r = 0;
    cin >> c;
    
    while (c!= '.') {
        
        if (c == 'a') r = r + 1;
        cin >> c;
    }
    
    cout << r << endl;
}

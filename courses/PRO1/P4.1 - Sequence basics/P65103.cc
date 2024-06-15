#include <iostream>
using namespace std;

int main() {

    double x,n,p=0;
    bool t = false;

    cin >> x;

    while (not t and (cin >> n)) {
        
        ++p;
        if (p == x) t = true;
        
    }

    if (t) cout << "A la posicio " << x << " hi ha un " << n << "." << endl;
    else cout << "Posicio incorrecta." << endl;

} 

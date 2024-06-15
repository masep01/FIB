#include <iostream>
using namespace std;

int main() {

    int n, x, p = 0;

    cin >> n;

    while ((cin >> x) and (x != (-1))) {
        ++p;

        if ((p == n)) cout << "A la posicio " << p << " hi ha un " << x << "." << endl;
        
    }
    

}
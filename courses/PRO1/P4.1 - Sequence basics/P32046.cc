#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int c, n, r = 0;

    cin  >> c;

    cout << "nombres que acaben igual que " << c << ":" << endl;

    while (cin >> n){

        if ((n%1000) == (c%1000)){
        ++r;
        cout << n << endl;
        }
    }

    cout << "total: " << r << endl;
    
} 
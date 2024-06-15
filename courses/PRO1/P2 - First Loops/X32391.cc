#include <iostream>
using namespace std;

int main() {

    int d, n, t, r, c=0;

    cin >> d >> n >> t;

    for (int i = t; i != 0; --i){

        cin >> r;
        n = n + r - d;
        
        if (n > 0) ++c;

    }

    cout << c << endl;
    
}   
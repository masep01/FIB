#include <iostream>
using namespace std;

int main() {

    cout.setf(ios::fixed);
    cout.precision(4);

    double c, i, t, u, a=1, r = 0;
    string tp;

    cin >> c >> i >> t >> tp;

    if ((tp == "simple")){

        r = c + c * (i/100) * t;

        cout << r << endl;

    } else if ((tp == "compost")){

        u = (1 + i/100);

        for (int j = 0; j < t; ++j) a = a*u;

        r = c*a ;

         cout << r << endl;
    }
    
}   
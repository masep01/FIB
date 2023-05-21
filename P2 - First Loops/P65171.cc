#include <iostream>
using namespace std;

int main() {

    cout.setf(ios::fixed);
    cout.precision(2);

    int n;
    cin >> n;

    double a = 1.0/(n-1);
    double b = 1.0/(n*(n-1));

    double c = 0;
    double d = 0;

    for (int i =0; i < n; i++){

        double x;
        cin >> x;

        c+= x*x;
        d+= x;
    }

    cout << (a*c) - (b*d*d) << endl;
    
}       
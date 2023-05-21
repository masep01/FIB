#include <iostream>
using namespace std;

int main() {

    double n,d, r;

    cin >> n;
    r = 0;
    d = 1;

    while (d <= n) {
        r = r + 1/d;
        d = d + 1;
    }
    cout.setf(ios::fixed);
    cout.precision(4);
    cout << r << endl;
}
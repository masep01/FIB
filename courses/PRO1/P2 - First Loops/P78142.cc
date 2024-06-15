#include <iostream>
using namespace std;

int main() {

    cout.setf(ios::fixed);
    cout.precision(2);

    double num, v, sum, m;
    
    sum = 0;
    v = 0;

    while (cin >> num) {
        sum += num;
        ++v;
    }

    m = sum / v;

    cout << m << endl;

}
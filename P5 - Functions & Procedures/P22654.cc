#include <iostream>	
#include <cmath>
using namespace std;

void descompon(int n, int& h, int& m, int& s) {
    h = 0;
    m = 0;
    s = n;

    if (s >= 60) {

        while (s >= 60) {
            s = s - 60;
            ++m;
        }
        while (m > 59) {
            m = m - 60;
            ++h;
        }
    }
}
    
int main () {
    int n, h = 0, m = 0, s = 0;

    cin >> n;

    descompon(n,h,m,s);
    cout << h << " " << m << " " << s;
}
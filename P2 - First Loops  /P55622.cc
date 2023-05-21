#include <iostream>
using namespace std;

int main() {

    int n,n1, r;

    r = 1;
    cin >> n;

    n1 = n;

    while (n > 9) {
        r = r + 1;
        n = n/10;
    }
    cout << "El nombre de digits de " << n1<< " es " << r << "." << endl;
  

}
#include <iostream>
using namespace std;

int main() {

    int x,a , r=0;
    cin >> x;

    while (cin >> a){

        if ((a % x) == 0) ++r;

    }
    cout << r << endl;

}   
#include <iostream>
using namespace std;


int main () {
    
    int n;
    
    cin >> n;

    if ((n == 0)) cout << n;
    
    while (n!= 0) {

        if ((n%16 == 10)) cout << "A";
        else if ((n%16 == 11)) cout << "B";
        else if ((n%16 == 12)) cout << "C";
        else if ((n%16 == 13)) cout << "D";
        else if ((n%16 == 14)) cout << "E";
        else if ((n%16 == 15)) cout << "F";
        else cout << n%16;

        n = n/16;
    }
    cout << endl;
}
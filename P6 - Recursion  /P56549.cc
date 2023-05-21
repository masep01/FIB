#include <iostream>	
#include <cmath>
using namespace std;

void bin(int n) {

    if (n < 2) cout << n;
    else {
        bin(n/2);
        cout << n%2;
    }

}
void oct(int n) {

    if (n < 8) cout << n;
    else {
        oct(n/8);
        cout << n%8;
    }

}

void hex(int n) {

    if (n == 10) cout << "A";
    else if (n == 11) cout << "B";
    else if (n == 12) cout << "C";
    else if (n == 13) cout << "D";
    else if (n == 14) cout << "E";
    else if (n == 15) cout << "F";
    else if (n < 16) cout << n;
    else {
        hex(n/16);
        if (n%16 == 10) cout << "A";
        else if (n%16 == 11) cout << "B";
        else if (n%16 == 12) cout << "C";
        else if (n%16 == 13) cout << "D";
        else if (n%16 == 14) cout << "E";
        else if (n%16 == 15) cout << "F";
        else cout << n%16;  
    }

}


int main () {
    int n;

    while (cin >> n) {

        if (n == 0) cout << "0 = 0, 0, 0" << endl;
        else {
            cout << n << " = ";
            bin(n);
            cout << ", ";
            oct(n);
            cout << ", ";
            hex(n);
            cout << endl;
        }
        
    }
}
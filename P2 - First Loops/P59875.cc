#include <iostream>
using namespace std;

int main() {

    int x, y;
    cin >> x >> y;

    if (x < y){

        for (int i = y; i != x; i--) {

            cout << i << endl;
        }
        cout << x << endl;

    } else if (y < x) {

        for (int i = x; i != y; i--) {

            cout << i << endl;
            
        }
        cout << y << endl;

    } else if ((x == y)) {

        cout << x << endl;
    } 

}
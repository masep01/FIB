#include <iostream>
using namespace std;

int main() {

    int a, b;
    bool primer = true;

    while (cin >> a >> b) {

        if (not primer) cout << endl;
        int x = 9;

       for (int i = 0; i < a; ++i){

            for (int j = 0; j < b; ++j) {

                cout << x;
                if ((x <= 9) and (x > 0)) --x;

                else x = 9;
            }
            cout << endl;
        }

        primer = false;
    }

}
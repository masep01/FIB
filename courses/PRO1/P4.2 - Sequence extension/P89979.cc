#include <iostream>	
using namespace std;

int main () {

    int n, linia = 1;
    bool found = false;

    
    
    while (cin >> n) {
        bool ordenada = false, primera = true;
        string anterior;

        if (n == 0) found = true;
        for (int i = 0; i < n; ++i) {

            string paraula;
            cin >> paraula;
            if (primera) {
                primera = false;
                ordenada = true;
            }
            else {
                if (paraula < anterior) ordenada = false;


            }
            anterior = paraula;
        }
        if (ordenada) found = true;
        if (not found) ++linia;

    }
    
    if (found) cout << "La primera linia ordenada creixentment es la " << linia << "." << endl;
    else cout << "No hi ha cap linia ordenada creixentment." << endl;
}
#include <iostream>	
#include <cmath>
using namespace std;

bool es_any_de_traspas(int any) {

    if ((any%4==0 and any%100!=0) or (any%400==0)) return true;
    else return false;
}

bool es_data_valida(int d, int m, int a) {

    bool valida = false;

    if (d > 0 and m > 0 and m <= 12 and a > 0 and a >= 1800 and a <= 9999) {

        if (m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12) {
            if (d <= 31) valida = true;
        } 
    
        else if (m == 2) {

            if (es_any_de_traspas(a)) {

                if (d <= 29) valida = true;
            }
            else if (d < 29) valida = true;
        } 
        else if (d < 31) valida = true;
    }
 
    return valida;
}

    
int main () {
    
    int d,m,a;

    cin >> d >> m >> a;

    if (es_data_valida(d,m,a)) cout << "true" << endl;
    else cout << "false" << endl;
}
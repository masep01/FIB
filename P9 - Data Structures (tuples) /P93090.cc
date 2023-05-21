#include <iostream>
#include <vector>
using namespace std;

struct Fraccio {
    int num, den;   // sempre estrictament positius
};

int mcd(int a, int b) {
    if (b == 0) return a;
    return mcd(b, a % b);
}

void simplificar(Fraccio& f){
    int div = mcd(f.num, f.den);
    f.num /= div;
    f.den /= div;
}

Fraccio suma(const Fraccio& x, const Fraccio& y){

    Fraccio f;
    
    if (x.den == y.den) {
        f.num = x.num + y.num;
        f.den = x.den;
        simplificar(f);

        return f;
    }
    else {

        f.num = (x.num * y.den) + (y.num * x.den);
        f.den = x.den * y.den;

        simplificar(f);
        return f;
    }

}

int main(){

    char c;

    Fraccio f1, f2;

    cin >> f1.num >> c >> f1.den;
    cin >> c;

    while (c != '=') {
        cin >> f2.num >> c >> f2.den;

        f1 = suma(f1,f2);

        cin >> c;
    }

    cout << f1.num << "/" << f1.den << endl;
}


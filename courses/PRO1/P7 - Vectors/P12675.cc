#include <iostream>
#include <vector>
using namespace std;

int busqueda_binaria (const vector <int>& v, int x) {

    int izq = 0;
    int dcha = v.size() - 1;

    while (izq <= dcha) {
        int m = (dcha+izq)/2;
        if (v[m] < x) izq = m +1;
        else if(x < v[m]) dcha = m-1;
        else return m;
    }
    return -1;

}

int elements_comuns (const vector<int>& X, const vector<int>& Y) {

    int l1 = X.size();
    int l2 = Y.size();
    int cont = 0;

    if (l1 > l2){

        for (int i = 0; i < l2; ++i){
            int x = Y[i];
            int pos = busqueda_binaria(X,x);
            if (pos != -1 and X[pos] == x) ++cont;
        }
    }
    else {
        for (int i = 0; i < l1; ++i){
            int x = X[i];
            int pos = busqueda_binaria(Y,x);
            if (pos != -1 and Y[pos] == x) ++cont;
            
        }
    }
    return cont;

}

int main() {



}
#include <iostream>
using namespace std;


int engreixa(int x) {
    
    if (x < 10) return x;
    else {
        int aux = engreixa (x/10);
        if (aux%10 > x%10) x = aux*10 + aux%10;
        else x = aux*10 + x%10;    
        return x;
    }
                                                           
}

int main() {
    int x;
    cin >> x;
    
    cout << engreixa(x) << endl;
}

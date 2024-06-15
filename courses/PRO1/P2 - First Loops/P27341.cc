#include <iostream>
using namespace std;

int main() {

    int a, b;
    
    while (cin >> a >> b) {

        int r = 0;
        
        for (int i = a; i <= b; ++i) r = r + (i*i*i);
        cout << "suma dels cubs entre " << a << " i " << b << ": " << r << endl;
        
    }

    

}   
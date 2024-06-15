#include <iostream>
using namespace std;

int main() {

    int a, a1;

    cin >> a;
    
    
    for (int i = 2; i <= 16; ++i) {

        int c = 0;
        a1 = a;

        while (a1 != 0) {

            a1 = a1/ i;
            ++c; 
        }

        cout << "Base " << i << ": " << c << " cifras." << endl;

    }
    
}
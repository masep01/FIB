#include <iostream>
using namespace std;

int main() {

    char l;
    bool b = true;
    int d1=0, d2 =0;
    
    while (cin >> l) {

        if (l == '(') ++d1;
        else {
            ++d2;
            if ( d2 > d1) b = false;
        }
        
    }

    if (b and d2 == d1) cout << "si" << endl;
    else cout << "no" << endl;


}


    

    
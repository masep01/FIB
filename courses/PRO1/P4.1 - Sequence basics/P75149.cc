#include <iostream>
using namespace std;

int main() {

    char l;
    bool found = false;


    while ((cin >> l) and (l != '.') and (found == false)){

        if (l == 'a') found = true;
    }

    if (found) cout << "si" << endl;
     else cout << "no" << endl;


}
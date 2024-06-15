#include <iostream>
using namespace std;

int main() {

    char l;
    int r = 0;

    while ((cin >> l) and (l != '.')){

        if (l == 'a') ++r;

    }
    cout << r << endl;

}
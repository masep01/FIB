#include <iostream>
using namespace std;

int main() {

    string p,x;
    int c = 1, r=1;

    cin >> p;

    while (cin >> x){

        if (p == x){
            
             ++c;
             if ( r <= c) r = c;
             

             }
        else c = 0;

    }
    cout << r << endl;

}

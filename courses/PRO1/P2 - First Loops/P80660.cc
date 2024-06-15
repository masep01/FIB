#include <iostream>
using namespace std;

int main() {

    int n, r = 0;

    
    while (cin >> n){

        while (n != 1){

            if (n%2 == 0){
                n = n/2;
                ++r;

            } else if (n%2 != 0) {
                n = 3*n + 1;
                ++r;
            }
            
        }
        cout << r << endl;
        r = 0;
    
    }
}
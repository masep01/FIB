#include <iostream>
using namespace std;

int main() {

    int a, b;
    bool primer = true;

    cin >> a >> b;
    
    if (a == b) {

        cout << a << endl;

    } else if (a < b){

        while ( a <= b) {
            
            if (primer) {

                cout << a;
                ++a;

                primer = false;

            } else {

                cout << "," << a;
                ++a;
                
            }
        }
        
        cout << endl;
        
    } else if (a > b) cout << endl;

    
}
#include <iostream>
using namespace std;

int main() {

    int x,p=0;
    bool found = false;

    while ((cin >> x) and not found){

        if (x%2 == 0){
            found = true;
            
        }
        ++p; 

    }
    cout << p << endl;

}

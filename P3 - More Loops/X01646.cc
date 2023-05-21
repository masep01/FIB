#include <iostream>
using namespace std;

int main() {

    int a,b, a1;
    cin >> b;

    while (cin >> a) {

        int r = 0;
        
        a1 = a;

        while (a1 != 0){
            
            r = r + a1%b;
            a1 = a1/b;
        }

        cout << a << ": " << r << endl;
        

    } 
  

}

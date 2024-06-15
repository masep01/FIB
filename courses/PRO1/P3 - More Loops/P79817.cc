#include <iostream>
using namespace std;

int main() {

    int a,b;

     while (cin >> a >> b) {


        if (b==0) cout << 1 << endl;

        else {

            int r=1;
            for (int i = 0; i < b; ++i) r = r*a;
            
            cout << r << endl;
            
        }
       
    }
  

}
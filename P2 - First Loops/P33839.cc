#include <iostream>
using namespace std;

int main() {

    int a, a1;

    while (cin >> a){

        int r=0;

        if (a > 9){
            a1 = a;

            while (a1 != 0){
                
                r = r + a1%10;
                a1 = a1/10;
            }
        
            cout << "La suma dels digits de " << a << " es " << r << "." << endl;
        } 

        else cout << "La suma dels digits de " << a << " es " << a << "." << endl;

       

    } 
  

}
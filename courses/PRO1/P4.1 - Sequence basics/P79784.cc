#include <iostream>
#include <cmath>
using namespace std;

int main() {

     char k;
     int x=0,y=0;
     
     while (cin >> k){
         
         if (k == 'e') ++x;
         else if (k == 'o') --x;
         else if (k == 's') ++y;
         else if (k == 'n') --y;
         
    }
    
    cout << "(" << x << ", " << y << ")" << endl;
} 

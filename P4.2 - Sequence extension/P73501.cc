#include <iostream>	
using namespace std;

int main () {
    
   int n;
   
   cin >> n;
   
   for (int i = 0; i < n; ++i) {
       
       int x1, x2, counter = 0;
       cin >> x1;
       while (x1 != 0){
            cin >> x2;
            if (x1 < x2) ++counter;
            x1 = x2;
        }
        
       cout << counter << endl;
    }
    
}

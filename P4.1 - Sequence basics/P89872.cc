#include <iostream>
using namespace std;

int main() {

   string x = "",r = "",max1 = "",max2 = "";
   

    while ((cin >> x >> r) and (x == r) ){}
    
    if (x > r){
        max1 = x;
        max2 = r;
    }
    else { 
        max1 = r;
        max2 = x;
    }

   
   while (cin >> x) {
       
       if ( x > max1) {
           max2 = max1;
           max1 = x;
       }
       else if (x > max2 and x < max1) max2 = x;
    }  
    
    cout << max2 << endl;
       
       
    
} 

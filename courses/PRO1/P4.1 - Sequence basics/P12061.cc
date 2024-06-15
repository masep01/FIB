#include <iostream>
using namespace std;

int main() {

   string p;
   int a=0;
   
   bool prim = false,ult= false;
   
   while (not ult and (cin >> p)){
       
        if (p == "principi") {
            prim = true;
        }
        if (prim) ++a;
        
        if ( p == "final") ult = true;
   
   }
   if (prim and ult) cout << a - 2 << endl;
   else cout << "sequencia incorrecta" << endl;
    
} 

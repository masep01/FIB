#include <iostream>
using namespace std;

int main(){
    
    int any;
    cin >> any;
    
    if ( ( (any % 4 == 0) and (any % 100 != 0) ) or ( (any % 100 == 0) and ( (any / 100) % 4 == 0)) ) 
        
        cout << "YES" << endl;
    
    else cout << "NO" << endl;
    
    
}

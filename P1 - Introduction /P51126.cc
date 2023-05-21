#include <iostream>
using namespace std;

int main(){
    
    int a1,b1,a2,b2,a3,b3;
    
    cin >> a1 >> b1 >> a2 >> b2;

    if (a2 > a1) a3=a2;
    else a3=a1;
    
    if (b2 > b1) b3 = b1;
    else b3=b2;
    

    if ( (a1 > b2) or (a2 > b1)) {
        cout << "[]" << endl;
        
    } else cout << "[" << a3 << "," << b3 << "]" << endl;
    
    
}

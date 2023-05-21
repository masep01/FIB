#include <iostream>
using namespace std;

int main(){
    
    int a1,b1,a2,b2,a3,b3;
    string r;
    
    cin >> a1 >> b1 >> a2 >> b2;

    if (a2 > a1) a3=a2;
    else a3=a1;
    
    if (b2 > b1) b3 = b1;
    else b3=b2;
    
    if ((a1 == a2) and (b1 == b2)) r = "=";
    else if (a2 <= a1 and b1 <= b2) r = "1";
    else if (a1 <= a2 and b2 <= b1) r = "2";
    else r= "?";

    if ( (a1 > b2) or (a2 > b1)) {
        cout << r << " , " << "[]" << endl;
        
    } else cout << r << " , " << "[" << a3 << "," << b3 << "]" << endl;
    
    
}

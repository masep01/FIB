#include <iostream>
using namespace std;

int main(){
    
    int a1,b1,a2,b2;
    string r;
    
    cin >> a1 >> b1 >> a2 >> b2;

    if ((a1 == a2) and (b1 == b2)) r = "=";
    else if (a2 <= a1 and b1 <= b2) r = "1";
    else if (a1 <= a2 and b2 <= b1) r= "2";
    else r= "?";
    
    
    cout << r << endl;
    
}

#include <iostream>
using namespace std;


int main(){
    
    int a,b,c, max;
    cin >> a;
    cin >> b;
    cin >> c;
    
    if (a>=b && a>= c) max = a ;
    else if (b>= a && b>= c) max = b;
    else max = c;

    cout << max << endl;
}
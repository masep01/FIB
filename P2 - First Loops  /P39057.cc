#include <iostream>
#include <cmath>
using namespace std;


int main () {
    
    cout.setf (ios::fixed);
    cout.precision (6);
    
    int n;
    string f;
    double a, b, r, s1, s2;
    
    
    cin >> n;
    
    
    for (int i = 0; i != n; ++i){
        
        cin >> f;
        
        if (f == "rectangle") {
            cin >> a >> b;
            s1 = a * b;
            cout << s1 << endl;
        } else if (f == "cercle") {
            cin >> r;
            s2 = M_PI * r * r;
            cout << s2 << endl;

        }
    }
    
    
    
}
    

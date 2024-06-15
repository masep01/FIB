 
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    cout.setf(ios::fixed);
    cout.precision(4);
    
   double n;
   
   cin >> n;
   
   for ( int j = 0; j < n; ++j) {
        double m;
        cin >> m;
        
        double x = 0, max = 0, min = 0, mit = 0;
        for (int i = 0; i < m; ++i) {
            
            cin >> x;
            
            if (i == 0) {
                min = x;
                max = x;
            } 
            
            if (x > max) max = x;
            else if (x < min) min = x;
            
            mit = mit + x;
            
            }
            
        mit = mit/m;
        
        cout << min << " " << max << " " << mit << endl;
   }
} 

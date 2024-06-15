#include <iostream>
using namespace std;

int main() {
    
    cout.setf(ios::fixed);
    cout.precision(10);

    double n1, n2;

    while (cin >> n1 >> n2) {
        double r = 0;
        
        for (int i = n2 + 1 ; i <= n1; ++i){
            
            r = r + 1/double(i);
        }   
        
        cout << r << endl;
        r = 0;
        
    }
}

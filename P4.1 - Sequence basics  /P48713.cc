#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int n, x;
    
    
    cin >> n;
    
    for (int i = 0; i < n; ++i){
        
        cin >> x;
        bool t = true;
        int div = 2;
        while (t and (div * div <= x)){
                
            if (x%div == 0) t = false;
            ++div;
        }

        if ((x > 1) and t) cout << x << " es primer" << endl;
        else cout << x << " no es primer" << endl;
    }
} 
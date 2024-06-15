#include <iostream>	
using namespace std;


int sum_min_max(int x, int y, int z){
    
    int max = 0, min = 0;
    
    if (x>y and x>z) {
        max = x;
        if (y>z) min = z;
        else min = y;
    }
    else if (y>x and y>z) {
        max = y;
        if (x>z) min = z;
        else min = x;
    }
    else { 
        max = z;
        if (x>y) min = y;
        else min = x;
    }
    
    return max + min;
}

int main () {
    int x, y, z;
    
    while (cin >> x >> y >> z) cout << sum_min_max(x, y, z) << endl;
        
}

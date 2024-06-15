#include <iostream>
using namespace std;

int main(){
    
    int n, n1, r=0;

    
    cin >> n;
    n1 = n;
    
    while (n != 0){
        
        r = r + n%2;
        n = n/100;
    }
        
    if (r%2 == 0) cout << n1 << " ES TXATXI" << endl;
    
    else if (r%2 != 0) cout << n1 << " NO ES TXATXI" << endl;
    
}

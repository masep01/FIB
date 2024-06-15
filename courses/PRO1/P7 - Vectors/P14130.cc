#include <iostream>
#include <vector>
using namespace std;


int main (){
    
    int n, counter = 0;
    cin >> n;
    
    vector<int> vec(n);
    int a;
    for (int j = 0; j < n; ++j) {
        cin >> a;
        vec[j] = a;
    }
    
    
    int ultim = vec[n-1];
    
    for (int i = 0; i < n-1; ++i) {
        
        if (vec[i] == ultim) ++counter;
        
    }
    cout << counter << endl;
}

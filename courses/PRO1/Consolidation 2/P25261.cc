#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool decreciente(int a, int b){
    if (a>b) return true;
    else return false;
}

int main() {

    int n;
    while (cin >> n) {

        vector<int> vec(n);
    
        for (int i = 0; i < n; ++i) cin >> vec[i];

        sort(vec.begin(), vec.end(), decreciente);

        for (int j = 0; j < n; ++j){
            if(j!=0) cout << " ";
            cout << vec[j];

        } 
        cout << endl;
    }

    
}
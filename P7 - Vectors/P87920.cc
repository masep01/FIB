#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;
    while (cin >> n) {

        vector<int> llista(n);
        int num;
        bool found = false;
        int suma = 0;

        for (int i = 0; i < n; ++i){
            cin >> num;
            suma += num;
            llista[i] = num;
        }

        for (int j = 0; (j < n) and (not found); ++j){
            
            num = llista[j];

            if (suma - num == num) found = true;
        }

        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
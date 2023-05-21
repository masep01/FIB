#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool primer(int n) {
    bool pr = false;
    int i = 0;
    
    if (n == 1 or n == 0) pr = true;
    else {
        pr = false;
        i = 2;
        while (i*i <= n and not pr){
            if (n%i == 0) pr = true;
            else i = i + 1;
        }
        
    }
    return not pr;
}

int main(){

    int n;
    while (cin >> n) {

        bool found = false;

        vector<int> vec(n);
        int x = 0;

        for (int i = 0; i < n; ++i){
            cin >> x;
            vec[i] = x;
        }

        x = 0;
        while ((x < n) and not found){

            for (int j = x + 1; j < n; ++j){
                    if (primer(vec[x] + vec[j])) found = true;
            }
            if (x != 0){
                for (int k = x - 1; k >= 0; --k){
                    if (primer(vec[x] + vec[k])) found = true;
                }
            } 

            ++x;
        }

        if (found) cout << "si" << endl;
        else cout << "no" << endl;
    }
    

}
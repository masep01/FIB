#include <iostream>
using namespace std;

int main() {

    int n;
    
    while (cin >> n) {
        int s = 2*n + (n - 2);
        
        for (int i = 0; i < s; ++i) {

            int x;
            if (i < n) x = i;
            else if ((i >= n) and (i <= s - n)) x = n-1;
            else x = s - 1 -i;
            int nX = n + 2*x;
            int nS = n - 1 - x;

            for (int j = 0; j < nS; ++j) cout << " ";
            for (int k = 0; k < nX; ++k) cout << "X";
            cout << endl;

        }
        cout << endl;
    }
    

}
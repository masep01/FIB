#include <iostream>	
#include <cmath>
using namespace std;



void cross(int n, char c) {

    for (int i = 0; i < n; ++i) {

        if(i == n/2) {

            for (int j = 0; j < n; ++j) cout << c;
            cout << endl;
        }
        else {

            for (int r = 0; r < n/2; ++r) cout << " ";
            cout << c << endl;
        }
    }

}
    

int main () {

    int n;
    char c;

    cin >> n >> c;

    cross(n,c);
    
}
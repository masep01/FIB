#include <iostream>	
#include <cmath>
using namespace std;


int factorial(int n){

    int fact = n;

    if (n == 0) return 1;
    else {

        for (int i = 1; i < n; ++i){
            fact = fact * (n - i);
        }
        
        return fact;
    }
}

int main () {
    int n;
    cin >> n;

    cout << factorial(n) << endl;
}
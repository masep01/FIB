
#include <iostream>	
#include <cmath>
using namespace std;



bool es_perfecte(int n) {
  
    int res = 1;
    for (int i = 2; i*i <= n; ++i) {

        if (n%i == 0) res = res + i+n/i;

    }

    if (n != 0 and n != 1) return (res == n);
    else return false;

}
    

int main () {

    int n;
    cin >> n;

    if (es_perfecte(n)) cout << "true" << endl;
    else cout << "false" << endl;
    
}
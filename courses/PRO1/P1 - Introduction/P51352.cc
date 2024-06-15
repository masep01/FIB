#include <iostream>
using namespace std;

int main() {
    
    char e1, e2, r;
    
    cin >> e1 >> e2;
    
    if ( ((e1== 'V') and (e2== 'A')) or ((e1== 'P') and (e2== 'V')) or ((e1== 'A') and (e2== 'P')) ) r = '1';
    else if (e1 == e2) r = '-';
    else r ='2';

    cout << r << endl;

}

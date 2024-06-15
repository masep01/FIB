#include <iostream>
using namespace std;

int main(){
    
    char w;
    
    cin >> w;
    
    if ((65 <= w) and (w <= 90)) cout << "majuscula" << endl;
    else if ((97 <= w) and (w <= 122)) cout << "minuscula" << endl;
    
    if ( (w == 65) or (w ==97) or (w ==69) or (w ==101) or (w ==73) or (w ==105) or (w ==79) or (w ==111) or (w ==85) or (w ==117) ) cout << "vocal" << endl;
    else cout << "consonant" << endl;
    
}

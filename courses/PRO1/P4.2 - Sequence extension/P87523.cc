#include <iostream>	
using namespace std;

int main () {
	
	char h, o, l, a;
	bool found = false;
	
	cin >> h >> o >> l >> a;
    
	while (not found and h != '.') {
    
        if (h == 'h' and o == 'o' and l == 'l' and a == 'a') found = true;
        
        else {
        h = o;
        o = l;
        l = a;
        cin >> a;
        }
    }
    if (found) cout << "hola" << endl;
    else cout << "adeu" << endl;
    
} 

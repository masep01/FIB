#include <iostream>
using namespace std;

void girar(int& n, int& c) {
	string word;
    
	if (cin >> word) {
        ++n;
        ++c;
        
        girar(n,c);
        
		if (c > 0 and c <= n/2) cout << word << endl;
        --c;
	}
	
}


int main () {
    int n = 0, c = 0;
	girar(n,c);
}

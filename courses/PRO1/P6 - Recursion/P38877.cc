#include <iostream>
using namespace std;

void girar(int& n) {
	string word;
    
	if (cin >> word) {
        girar(n);
		if (n > 0){ 
            cout << word << endl;
            --n;
        
            
        }
	}
	
}


int main () {
    int n = 0;
    cin >> n;
    
	girar(n);
}

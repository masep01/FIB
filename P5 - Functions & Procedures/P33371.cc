#include <iostream>	
using namespace std;

char codificat(char c, int k) {
	
	if (k>26)k = k%26;
	
	for (int i = 1; i <= k; ++i) {
		++c;
		if (c > 'z') c = c - 26;
	}
	return c - 32;
}

int main () {
	
	int k;
	char c;
	
	while (cin >> k) {
		
		cin >> c;
		while (c != '.') {
			
			if (c == '_') cout << " ";
			else if (c == ',') cout << c;
			else if (c == '-') cout << c;	
			else if (not (c>=97 and c<=122)) cout << c;
			else cout << codificat(c, k);
			
			cin >> c;	
		}
		cout << endl;
	}	
	
}

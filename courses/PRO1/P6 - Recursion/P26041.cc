#include <iostream>
using namespace std;

void girar() {
	string word;
	if (cin >> word) {
		girar();
		cout << word << endl;
	}
	
}


int main () {

	girar();
}

#include <iostream>
using namespace std;

void girar() {
	string word;
	if (cin >> word) {
		if (word != "fi") {girar();
		cout << word << endl;}
	}
	
}


int main () {

	girar();
}

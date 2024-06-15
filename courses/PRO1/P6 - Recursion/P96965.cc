#include <iostream>	
using namespace std;

int suma_digits(int x) {
	
	if (x < 10) return x%10;
	else return suma_digits(x/10) + x%10;
}

int reduccio_digits(int x) {
	
	if (x == 10) return 1;
	else {
		
		while (x >= 10) {
			x = suma_digits(x);
		}
		
		return x;
	}
}

int main () {
	
	int x;
	cin >> x;
	
	cout << reduccio_digits(x) << endl;
	
	
}

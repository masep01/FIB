#include <iostream>
using namespace std;

int suma_digits(int n){
	if(n < 10) return n;
	else return n%10 + suma_digits(n/10);
}

bool es_multiple_3(int n){
	return suma_digits(n)%3 == 0;
}

int main() {
	
	int n;
	cout << "Introdueix el nombre: ";
	cin >> n;
	
	cout << "El nombre * " << n << " *";
	if(es_multiple_3(n)) cout << " SI es múltiple de 3." << endl;
	else cout << " NO és multiple de 3." << endl;

}


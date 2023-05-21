#include <iostream>	
using namespace std;


int mcd(int a, int b) {
    int aux;
    
    while (b != 0) {
        aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

void read_rational(int& num, int& den) {
	
	char bar = 0;
	
	cin >> num >> bar >> den;
	
	int i = mcd(num,den);
	
	num = num / i;
	den = den / i;
}

int main () {
	
	int num = 0;
	int den = 0;
	
	read_rational(num,den);
	
	cout << num << "/" << den;
}

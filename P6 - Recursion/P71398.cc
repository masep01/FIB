#include <iostream>
using namespace std;

void digit_maxim_i_minim(int n, int& maxim, int& minim){
	maxim = n%10;
	minim = n%10;
	
	if ((n == 0) or (n < 10)) {
		maxim = n;
		minim = n;
	}
	else{
		digit_maxim_i_minim(n/10, maxim , minim);
		if (n%10 > maxim) maxim = n%10;
		if (n%10 < minim) minim = n%10;
	}
}

int main () {
	
	int n, maxim = 0, minim = 0;
	cin >> n;
	digit_maxim_i_minim(n,maxim,minim);
	cout << "max: " << maxim << " min: " << minim << endl;
	
}

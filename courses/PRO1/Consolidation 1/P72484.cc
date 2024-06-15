#include <iostream>
using namespace std;

int main() {

	int n;
	
	cin >> n;
	
	if (n != 0){
		
		for(int i = 1; i <= n; ++i) {
			
			for (int k = i; k < n; ++k) cout << " ";
			if (i == 1) cout << "*";
			else {
				for (int l = 0; l < i; ++l) cout << "*";
				for (int l = 1; l < i; ++l) cout << "*";
			}
			cout << endl;
		}
		
		for (int j = 2*n - 1; j > n ; --j) {
			
			for (int m = 0; m < 2*n - j; ++m) cout << " ";
			if (j == n - 1) cout << "*";
			else {
				for (int o = 0; o < j - n; ++o) cout << "*";
				for (int p = 1; p < j - n; ++p) cout << "*";
			}
			cout << endl;
		}
		
	}

}


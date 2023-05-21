#include <iostream>
using namespace std;

int main() {
	
	cout.setf(ios::fixed);
	cout.precision(4);		
	
	double a, b, k,res = 0;
	
	while (cin >> a >> b >> k){
		int n = 1;
		res = 1/a;
		
		while ((a + n*k) <= b) {
			
			res = res + (1 / (a + n*k));
			++n;
			
		}
			cout << res << endl;
	}

	

	
}

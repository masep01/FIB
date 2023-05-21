#include <iostream>	
using namespace std;

int main () {

	int x0,x1,x2;
	
	bool found = false;
	
	cin >> x0 >> x1;
	
	while (cin >> x2 and x2 != 0) {
		
		if (x1 > 3143 and x0 < x1 and x2 < x1) found = true;
		x0 = x1;
		x1 = x2;
		
	}
	
	if (found) cout << "SI" << endl;
	else cout << "NO" << endl;
}

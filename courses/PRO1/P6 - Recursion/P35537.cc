#include <iostream>
using namespace std;

bool es_creixent(int n) {
	
	if (n <= 9) return true;
    else if (n%10 < (n/10)%10) return false;
    return es_creixent(n/10);
	
}


int main () {
	int n;
	
	cin >> n;
	
	if (es_creixent(n)) cout << "true" << endl;
	else cout << "false" << endl;
}

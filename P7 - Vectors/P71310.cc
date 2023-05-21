#include <iostream>
#include <vector>
#include <string>
using namespace std;


double producte_escalar(const vector<double>& u, const vector<double>& v) {
	
	double producte = 0;
	int n = u.size();
	for (int i = 0; i < n; ++i) {
		
		producte += u[i] * v [i];
		
	}
	return producte;
}

int main() {
 
 	
 	
 	
}

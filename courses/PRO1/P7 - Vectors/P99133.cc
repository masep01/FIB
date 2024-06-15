#include <iostream>
#include <vector>
#include <string>
using namespace std;


void girar(string& paraula) {
	
	string paraula2 = "";
	
	for (int i = paraula.size() - 1; i >= 0; --i) {
		paraula2 = paraula2 + paraula[i];
	}
	
	paraula = paraula2;
}

int main() {
 
 	int n;
 	string paraula;
 	
 	cin >> n;
 	
 	vector<string> llista(n);
 	
 	for (int i = 0; i < n; ++i) {
 		cin >> paraula;
 		
 		llista[i] = paraula;
	}
 	
 	for (int j = n - 1; j >= 0; --j) {
 		
 		paraula = llista[j];
 		girar(paraula);
 		
 		cout << paraula << endl;
	}
 	
 	
 	
}

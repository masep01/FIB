#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Professor{
	string nom;
	int carrot;
	int carmel;
	
};

bool esMillor(Professor a, Professor b){
	
	if(a.carmel > b.carmel) return true;
	if(a.carmel < b.carmel) return false;
	
	if(a.carrot > b.carrot) return true;
	if(a.carrot < b.carrot) return false;
	
	if(a.nom.size() < b.nom.size()) return true;
	if(a.nom.size() > b.nom.size()) return false;
	return a.nom < b.nom;
	
	
}


int main(){
	
	int n;
	
	cin >> n;
	
	for(int i = 0; i < n; ++i){
		
		int p;
		cin >> p;
		
		vector<Professor> llista(p);
		
		for(int j = 0; j < p; ++j) cin >> llista[j].nom >> llista[j].carmel >> llista[j].carrot; 
		
		sort(llista.begin(),llista.end(),esMillor);
		
		for(int k = 0; k < p; ++k) cout << llista[k].nom << endl;
		cout << endl;
	}
}

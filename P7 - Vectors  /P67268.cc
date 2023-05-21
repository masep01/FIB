#include <iostream>
#include <vector>
using namespace std;

int main () {
	
	int n = 0;
	while (cin >> n){
	
	
		vector<int> vec(n);
		int a = 0;
		
		for (int j = 0; j < n; ++j) {
	        cin >> a;
	        vec[j] = a;
	    }
	    
	    for (int i = n - 1; i >= 0; --i) {
	    	cout << vec[i];
	    	if (i!=0) cout << " ";
		}
		cout << endl;
	}
}

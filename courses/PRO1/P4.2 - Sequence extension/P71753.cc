#include <iostream>
using namespace std;

int main() {

	int range, num, max;
	
	while (cin >> range) {
		
		cin >> max;
		
		for (int i = 1; i < range; ++i){
			
			cin >> num;
			if (num > max) max = num;
		}
		cout << max << endl;	
	}
}

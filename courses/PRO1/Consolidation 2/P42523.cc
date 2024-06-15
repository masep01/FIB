#include <iostream>
using namespace std;

 int mcd(int a, int b){
 	
	if (b==0) return a;
	else return mcd(b, a%b);	
 }
 
int main() {
	int a, b;
	
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	
	cout << "mcd(" << a << "," << " " << b << ") = " << mcd(a,b) << endl;

}


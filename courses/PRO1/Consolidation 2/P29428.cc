#include <iostream>
#include <vector>
using namespace std;

bool conte(string s1, string s2) {
	int i = 0;
	bool trobat = (s1.size() == 0);
	int n = int(s2.size())-int(s1.size());

	while (not trobat and i <= n) {
		int j = 0;
		bool encaixa = true;
		while (encaixa and j < s1.size()) {
			encaixa = (s1[j] == s2[i+j]);
			j++;
		}
		if (encaixa) trobat = true;
		else i++;
	}
	if (trobat) return true;
	else return false;
}

int main() {
	int n;
	cin >> n;

	vector <string>seq(n);
	for (int i = 0; i < n; i++) cin >> seq[i];
	for (int i = 0; i < n; i++) {
		cout << seq[i] << ':';
		for (int j = 0; j < n; j++) {
			if (conte(seq[j], seq[i])) cout << ' ' << seq[j];
		}
		cout << endl;
	}
}
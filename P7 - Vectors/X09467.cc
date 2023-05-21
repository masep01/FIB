#include <iostream>
#include <vector>
using namespace std;

vector <bool>pos_rampas(const vector <int>& V) {
	int x0 = V[0];
	int x1 = V[1];

	vector <bool>positions(V.size());
	for (int i = 2; i < V.size(); i++) {
		if ((x0 < x1 and x1 < V[i]) or
		    (x0 > x1 and x1 > V[i])) {
			positions[i-2] = true;
		} else positions[i-2] = false;
		x0 = x1;
		x1 = V[i];
	}

	return positions;
}

int pot_conflictives(const vector <bool>& B) {
	int c = 0;

	for (int j = 0; j < B.size()-2; ++j) {
		if (B[j] and B[j+1]) c++;
		if (B[j] and B[j+2]) c++;
	}
	return c;
}

int main() {
	int n;
	while (cin >> n) {
		vector <int>num_list(n);
		for (int i = 0; i < n; i++) {
			cin >> num_list[i];
		}
		vector <bool>posiciones = pos_rampas(num_list);
		cout << "posicions amb rampa:";
		for (int i = 0; i < posiciones.size(); i++) {
			if (posiciones [i] == 1) cout << ' ' << i;
		}
		cout << endl;
		cout << "potencialment conflictives: " << pot_conflictives(posiciones) << endl;
		cout << "---" << endl;
	}
}
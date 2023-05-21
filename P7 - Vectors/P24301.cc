#include <iostream>
#include <vector>
using namespace std;

vector<int> concatenacio(const vector<int>& v1, const vector<int>& v2) {

    int l1 = v1.size();
    int l2 = v2.size();

    vector <int> final(l1 + l2);

    for(int i = 0; i < l1; ++i) final[i] = v1[i];
    for(int j = 0; j < l2; ++j) final[j+l1] = v2[j];

    return final;


}

/*
int main() {

    int n,s; 
    cin >> n;
    vector <int> v1(n);
    for (int i = 0; i < n; ++i) {
        cin >> s;
        v1[i] = s;
    }

    cin >> n;
    vector <int> v2(n);
    for (int j = 0; j < n; ++j) {
        cin >> s;
        v2[j] = s;
    }     
    
    for (int l = 0; l < concatenacio(v1,v2).size(); ++l){
        cout << concatenacio(v1,v2)[l];
    }
} 
*/
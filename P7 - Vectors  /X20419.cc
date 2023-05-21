#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

double mitjana(vector<string> llista){

    int l = llista.size();
    double mitjana = 0;

    string word;

    for (int j = 0; j < l; j++) {
        word = llista[j];
        mitjana = mitjana + word.size();
        
    }
    return mitjana/l;
    
}

char lletra_mes_frequent(const string& s){
    string w = s;

    sort(w.begin(), w.end());

    char lletra = ' ', l_max = ' ';
    int cont = 1, cont_max = 0;

    for (int r = 0; r < w.size(); ++r){
        
        if (lletra == w[r]) ++cont;
        else cont = 1;

        if(cont_max < cont){
            cont_max = cont;
            l_max = w[r];
        }
        lletra = w[r];
    }
    return l_max;
}


int main() {

    cout.setf(ios::fixed);
    cout.precision(2);
    

    int n;
    cin >> n;

    vector<string> llista(n);
    string x = "";

    for(int i = 0; i < n; ++i){
        cin >> x;
        llista[i] = x;
    }

    double mit = mitjana(llista);

    cout << mit << endl;

    for (int k = 0; k < llista.size(); ++k){
        x = llista[k];

        if (x.size() >= mit){

            cout << x << ": " << lletra_mes_frequent(x);
            cout << endl;

        }
    }
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool es_palindrom(const string& s){

    
    int l = s.size();

    for (int i = 0; i < l/2; ++i) {
        if (s[i] != s[l - i -1]) return false;

    }
    return true;
   
}


int main() {

    string word;

    cin >> word;

    if (es_palindrom(word)) cout << "true" << endl;
    else cout << "false" << endl;
} 
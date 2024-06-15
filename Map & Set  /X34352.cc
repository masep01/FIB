#include <iostream>
#include <map>
using namespace std;


int main(){

    map<string, int> m;
    pair<char, string> p;

    while(cin >> p.first >> p.second){
        
        if(p.first == 'a')++m[p.second];
        else cout << m[p.second] << endl;
    }
}
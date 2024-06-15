#include <iostream>
#include <map>
using namespace std;


int main(){

    map<string, int> m;
    pair<char, string> p;

    while(cin >> p.first >> p.second){

        if(p.first == 'a') ++m[p.second];
        else if(p.first == 'e'){
            map<string, int>::iterator it = m.find(p.second);
            if(it == m.end()) ++m[p.second];
            else if(m[p.second] != 0) --m[p.second];
        }
        else cout << m[p.second] << endl;
    }
}
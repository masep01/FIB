#include <iostream>
#include <vector>
#include <set>
using namespace std;

void posa(const vector<char> &v, set<string> &S)
{
    string w;
    for (int i = 0; i < int(v.size()); i++) w.push_back(v[i]);
    S.insert(w);
}

bool vocal(char c)
{
    return (c == 'a') or (c == 'e') or (c == 'i') or (c == 'o') or (c == 'u');
}

bool cond(char esq, char dre)
{
    if(vocal(esq)) return not vocal(dre);
    if(vocal(dre)) return not vocal(esq);
    return true;
}

void runes(int n, int i, const string &chars, vector<char> &V, set<string> &S)
{
    if(i == n) posa(V,S);
    else
    {
        for(int k = 0; k < int(chars.size()); ++k)
        {
            if((i == 0 or cond(V[i-1], chars[k])))
            {
                V[i] = chars[k];
                runes(n,i+1,chars,V,S);    
            }
        }
    }
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        string chars;
        cin >> chars;
        vector<char> V(n); 
        set<string> S;
        runes(n, 0, chars, V, S);
        for(auto w : S) cout << w << endl;
        cout << "----------" << endl;    
    }
}
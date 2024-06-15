#include <iostream>
#include <vector>
using namespace std;

vector<char> vocals;
vector<char> consonants;
int n;

void escriu(const vector<char> &v)
{
    for (int i = 0; i < int(v.size()); i++) cout << v[i];
    cout << endl;
}

bool es_vocal(char c)
{
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

void perm(int i, vector<char> &V, vector<bool> &UC, vector<bool> &UV)
{
    if(i == n*2) escriu(V);
    else
    {   
        if(i%2==0)
        {
            for(int k = 0; k < n;++k)
            {
                if(i == 0 or not UC[k])
                {
                    V[i] = consonants[k];
                    UC[k] = true;
                    perm(i+1, V, UC, UV);
                    UC[k] = false;
                }
            }
        }
        else
        {
            for(int k = 0; k < n;++k)  
            {
                if(not UV[k])
                {
                    V[i] = vocals[k];
                    UV[k] = true;
                    perm(i+1, V, UC, UV);
                    UV[k] = false;
                }
            } 
        }  
    }
}

int main()
{
    
    cin >> n;

    vocals = vector<char>(n);
    consonants = vector<char>(n);
    for(int i = 0; i < n;++i) cin >> consonants[i];
    for(int i = 0; i < n;++i) cin >> vocals[i];

    vector<char> V(n*2);
    vector<bool> UC(n, false);
    vector<bool> UV(n, false);
    perm(0,V,UC, UV);
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void escriu(const vector<string> &V)
{
    for (int i = 0; i < int(V.size()); i++) cout << V[i];
    cout << endl;
}

void la_meva_func(int i, vector<string> &V, const vector<string> &paraules, vector<bool> &usat)
{
    int n = V.size();
    if(i == n) escriu(V);
    else
    {
        for (int j = 0; j < n; j++)
        {
            if(not usat[j])
            {
                if(i == 0 or V[i-1][V[i-1].length()-1] != paraules[j][0])
                {
                    V[i] = paraules[j];
                    usat[j] = true;
                    la_meva_func(i+1,V,paraules,usat);
                    usat[j] = false;
                }
            }
        }
        
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> paraules(n);
    vector<string> v(n);
    vector<bool> usat(n, false);
    for (int i = 0; i < n; i++) cin >> paraules[i]; 
    la_meva_func(0,v,paraules, usat);
}
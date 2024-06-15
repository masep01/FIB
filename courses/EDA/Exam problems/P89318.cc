#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
const vector<char> LLETRES = {'a','b','c','d','e','f','g','h','i'};

void escriu(const vector<char> &v)
{
    for (int i = 0; i < n; i++) cout << v[i]; 
    cout << endl; 
}

void perm(int i, vector<char> W, vector<bool> &usat)
{
    if(i == n) escriu(W);
    else
    {
        for(int k = 0; k < n; ++k)
        {
            if(not usat[k] and (i == 0 or W[i-1]+1 != LLETRES[k]))
            {
                W[i] = LLETRES[k];
                usat[k] = true;
                perm(i+1,W,usat);
                usat[k] = false;
            }
        }
    }
}
int main()
{
    cin >> n;
    vector<char> w(n);
    vector<bool> usat(n);
    perm(0,w,usat);
}
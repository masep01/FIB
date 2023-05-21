#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<char> C = {'x','y','z'};

void escriu(const vector<char> &V)
{
    for (int i = 0; i < int(V.size()); i++) cout << V[i];
    cout << endl;
}

void prefixos(int i, vector<char> &V, int u)
{
    if(i == n) escriu(V);
    else
    {
        for(int k = 0; k < 3; ++k)
        {
            int x = u;
            if(i>0 and V[i-1] == C[k]) ++x;  
            else x = 1;

            if(x <= m)
            {
                V[i] = C[k];
                prefixos(i+1,V,x);
            } 
        }
    }
}

int main()
{
    while(cin >> n >> m)
    {
        vector<char> V(n);
        prefixos(0,V,0);
        cout << "--------------------" << endl;
    }    
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void escriu(const vector<char> &V)
{
    for (int i = 0; i < int(V.size()); i++) cout << V[i];
    cout << endl;
}

void adn(int i, const vector<char> &c, vector<char> &V)
{
    if(i == int(V.size())) escriu(V);
    else
    {
        for(int k = 0; k < 4;++k)
        {
            V[i] = c[k];
            adn(i+1,c,V);
        }
    }
}

int main() 
{
    int n;
    cin >> n;
    vector<char> c = {'A', 'C', 'G', 'T'};
    vector<char> V(n);
    adn(0,c,V);
}

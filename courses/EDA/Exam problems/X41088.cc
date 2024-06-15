#include <iostream>
#include <vector>
using namespace std;


void escriu(const vector<int> &V)
{
    int n = V.size();
    cout << "(";
    for (int i = 0; i < n; i++)
    {
        cout << V[i];
        if(i != n-1) cout << ",";
    }
    cout << ")" << endl;
}


void equi(int i, vector<int> &V, vector<bool> &usat)
{
    if(i == int(V.size())) escriu(V);
    else
    {
        for (int k = 1; k <= int(V.size()); k++)
        {
            if(not usat[k] and ((i < 2) or (V[i-2]+k <= 2*V[i-1])))
            { 
                V[i] = k;
                usat[k] = true;
                equi(i+1,V,usat);
                usat[k] = false;
            }
        }
        
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<bool> usat(n+1, false);
    equi(0,v,usat);

}
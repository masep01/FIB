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


void equi(int i, int d, vector<int> &V, vector<bool> &usat)
{
    if(i == int(V.size())) escriu(V);
    else
    {
        for (int k = 1; k <= int(V.size()); k++)
        {
            if(not usat[k] and (i == 0 or abs(V[i-1]-k) <= d))
            { 
                V[i] = k;
                usat[k] = true;
                equi(i+1,d,V,usat);
                usat[k] = false;
            }
        }
        
    }
}

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    vector<bool> usat(n+1, false);
    equi(0,d,v,usat);

}
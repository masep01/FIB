#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void escriu(const vector<int> &v)
{
    cout << "(";
    for (int i = 0; i < v.size()-1; i++) cout << v[i] << ",";
    cout << v[v.size()-1] << ")" << endl;    
}

void perm(int i, vector<int> &v, vector<bool> &usat, int n)
{
    int a =  v.size();
    if(i == a) escriu(v);
    else
    {   
        for(int k = 1; k <=n; ++k)
        {
            if(not usat[k])
            {
                v[i] = k;
                usat[k] = true;
                perm(i+1,v,usat,n);
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
    vector<bool> usat(n+1);
    perm(0,v, usat, n);

}
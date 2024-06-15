#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void escriu(const vector<int> &v)
{
    for (int i = 0; i < v.size()-1; i++) cout << v[i] << " ";
    cout << v[v.size()-1] << endl;    
}

void zeros(int i, vector<int> &v, int z, int u, int k)
{
    int n =  v.size();
    if(i == n) escriu(v);
    else
    {   
        if(z < n-k)
        {
            v[i] = 0;
            zeros(i+1, v, z+1, u, k);
        }

        if(u < k)
        {
            v[i] = 1;
            zeros(i+1, v, z, u+1, k);
        }  
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    zeros(0,v, 0, 0, k);

}
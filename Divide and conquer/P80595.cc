#include <iostream>
#include <vector>
using namespace std;

int fus(vector<int> &v, int e, int m , int d)
{
    int n = 0;
    vector<int> aux(d - e + 1);
    int i, j, k;
    i = e; j = m+1; k = 0;
    while(i <= m and j <= d)
    {
        if(v[i] <= v[j])
        {
            aux[k] = v[i];
            ++i; ++k;
        }
        else
        {
            aux[k] = v[j];
            ++j; ++k;
            n += (m - i + 1);
        }
    }

    while(i<=m)
    {
        aux[k] = v[i];
        ++i;
        ++k;
    }
    while(j<=d)
    {
        aux[k] = v[j];
        ++j;
        ++k;
    }
    for(k = 0; k < d-e+1;++k) v[e+k] = aux[k];
    return n;
}

int n_inv(vector<int> &v, int e, int d)
{
    if(e >= d) return 0;
    int m = (e+d)/2;
    int a = n_inv(v, e, m);
    int b = n_inv(v, m+1, d);
    int c = fus(v, e, m , d);
    
    return a+b+c;
}


int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> v(n);
        for(auto i = 0; i < n; ++i) cin >> v[i];
        cout << n_inv(v, 0 , n-1) << endl;
    }
}
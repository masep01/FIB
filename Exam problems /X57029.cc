#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<char> &v)
{
    for (int i = 0; i < int(v.size()); i++) cout << v[i];
    cout << endl;
}

void perm(int i, vector<char> &v, int u)
{
    int x =  v.size();
    if(i == x) escriu(v);
    else
    {   
        if(u > 0) 
        {
            v[i] = 'd';
            perm(i+1,v,u-1);
        }  
        v[i] = 'h';
        perm(i+1,v,u);

        v[i] = 'u';
        perm(i+1,v,u+1);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<char> v(n);
    perm(0, v, 0);
}
#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<char> &v)
{
    for (int i = 0; i < int(v.size()); i++) cout << v[i];
    cout << endl;
}

void perm(int i, vector<char> &v, int a, int b)
{
    int x =  v.size();
    if(i == x) escriu(v);
    else
    {   
        if(abs(a+1-b) <= 2) 
        {
            v[i] = 'a';
            perm(i+1,v,a+1,b);
        }  
        if(abs(a-b-1) <= 2) 
        {
            v[i] = 'b';
            perm(i+1,v,a,b+1);
        } 
    }
}

int main()
{
    int n;
    cin >> n;
    vector<char> v(n);
    perm(0, v, 0, 0);
}
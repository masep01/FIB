#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<char> &v)
{
    for (int i = 0; i < int(v.size()); i++) cout << v[i];
    cout << endl;
}

void perm(int i, vector<char> &v, int x, int c)
{
    int a =  v.size();
    if(i == a) escriu(v);
    else
    {   
        if(c>0 ) 
        {
            v[i] = 'b';
            perm(i+1,v,x+1,c-1);
        }
        if(x>0 ) 
        {
            v[i] = 's';
            perm(i+1,v,x-1,c+1);
        }   
    }
}

int main()
{
    int n, c;
    cin >> n >> c;
    vector<char> v(n);
    perm(0, v, 0, c);
}
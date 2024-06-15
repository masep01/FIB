#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void escriu(const vector<string> &v)
{
    cout << "(";
    for (int i = 0; i < v.size()-1; i++) cout << v[i] << ",";
    cout << v[v.size()-1] << ")" << endl;    
}

void perm(int i, const vector<string> &w, vector<string> &v, vector<bool> &usat, int n)
{
    int a =  v.size();
    if(i == a) escriu(v);
    else
    {   
        for(int k = 0; k <n; ++k)
        {
            string word = w[k];
            if(not usat[k])
            {
                v[i] = word;
                usat[k] = true;
                perm(i+1,w,v,usat,n);
                usat[k] = false;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> w(n);
    for(int i = 0; i<n; ++i) cin >> w[i];
    vector<bool> usat(n);
    vector<string> v(n);
    perm(0,w, v, usat, n);

}
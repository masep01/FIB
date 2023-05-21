#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> divs;

bool es_multiple(int n)
{
    for (int i = 0; i < m; i++)
    {
        if(n%divs[i]==0) return true;
    }
    return false;
}

void prefixos(int i,int num)
{
    if(i == n) cout << num << endl;
    else
    {
        for(int k = 0; k < 10; ++k)
        {
            int x = k+num*10;
            if(not es_multiple(x))
            {
                prefixos(i+1, x);
            }
        }
    }
}

int main()
{
    while(cin >> n >> m)
    {
        divs = vector<int>(m);
        for (int i = 0; i < m; i++) cin >> divs[i];
        vector<int> V(n);
        prefixos(0,0);
        cout << "----------" << endl;
    }    
}
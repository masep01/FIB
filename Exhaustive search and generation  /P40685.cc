#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> v;

void printa_sol(vector<bool> &sol)
{
    bool primer = true;
    cout << "{";
    for(int i = 0; i < m; ++i)
    {
        if(sol[i])
        {
            if(not primer) cout << ",";
            else primer = false;
            cout << v[i];
        }
    }
    cout << "}" << endl;
}

void subsets(int l, vector<bool> &sol, int p_sum)
{
    if(l == m)
    {
        if(p_sum == n) printa_sol(sol);
    }
    else
    {
        sol[l] = false;
        subsets(l + 1, sol, p_sum);
        sol[l] = true;
        subsets(l + 1, sol, p_sum + v[l]);
    }
}

int main()
{
    cin >> n >> m;
    v = vector<int>(m);
    for(int i = 0; i<m;++i) cin >> v[i];
    vector<bool> sol(m, false);
    subsets(0, sol, 0);

}
#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graph;

bool color(const Graph &G, vector<int> &v, int u, int c)
{
    if(v[u] == 0)
    {
        v[u] = c;
        for(int i : G[u]) 
        {
            if(c == 1 and not color(G,v,i,2)) return false;
            else if(c == 2 and not color(G,v,i,1)) return false;
        }
        return true;
    }
    else return v[u] == c;
}

bool dfs_c(const Graph &G)
{
    vector<int> v(G.size(),0);       // 0 sense pintar
    for(int i = 0; i < int(G.size()); ++i)
    {
        if(v[i] == 0 and not color(G,v,i,1)) return false;
    }
    return true;
}

int main()
{
    int n,m;
    while(cin >> n >> m) {
        Graph G(n);
        for(int i = 0; i < m; ++i)
        {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        if(dfs_c(G)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
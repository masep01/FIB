#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graph;

int dfs_rec (const Graph& G, vector<bool>& vis, int u) {
    if (vis[u]) return 0;
    vis[u] = true;
    int l=1;
    for (int v : G[u]) l += dfs_rec(G,vis,v);
    return l;
}

int main()
{
    int n,m;
    while(cin >> n >> m){
        Graph G(n);
        vector<bool> vis(n, false);
        for(int i = 0; i < m; ++i)
        {
            int x,y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        int mini = 1e8;
        int maxi = 0;
        
        for (int x = 0; x < n; ++x)
        {
            if (not vis[x]) 
            {
                int q = dfs_rec(G, vis, x);
                mini = min(mini, q);
                maxi = max(maxi, q);
            }
        }
        cout << mini << ' ' << maxi << endl;
    }
}
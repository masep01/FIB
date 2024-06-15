#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> Graph;
int n, u, v, m;
Graph G;
Graph G_f;

void read_graph()
{
    G = Graph(n);
    G_f = Graph(n);
    int x, y;       
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        G[x].push_back(y);
        G_f[y].push_back(x);
    }
}

void dfs(int a, const Graph &G, vector<bool> &vis)
{
    if(vis[a]) return;
    vis[a] = true;
    for(auto x : G[a]) dfs(x,G,vis);
}

void inter()
{
    int Q = 0;
    vector<bool> vis(n, false);
    dfs(u,G,vis);
    if(not vis[v]) {cout << Q << endl; return;}

    vector<bool> vis_f(n, false);
    dfs(v,G_f,vis_f);
    
    for (int i = 0; i < n; i++)
    {
       if(vis[i] and vis_f[i]) ++Q;
    }
    cout << Q-2 << endl;
}

int main()
{
    while (cin >> n >> u >> v >> m)
    {
        read_graph();
        inter();
    }
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> Graph;

void mi_func(const Graph &G)
{
    int n = G.size();
    vector<int> dist(n,-1);
    queue<int> Q;
    Q.push(0);
    dist[0] = 0;
    while(not Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int v : G[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = dist[u]+1;
                Q.push(v);
                
            }
            
        }   
    }
    int max = 0;
    for(int i = 1; i < n;++i)
    {
        if(dist[i] != -1 and dist[i] > dist[max]) max = i;
    }
    cout << max << endl;
}

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        Graph G(n);
        int x,y;
        for (int i = 0; i < m; i++)
        {   
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        mi_func(G);
    }
}
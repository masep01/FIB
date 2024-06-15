#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<double, int> ArcP; // arc amb pes
typedef vector< vector<ArcP> > GrafP; // graf amb pesos

void dijkstra(const GrafP &G, int s, int f)
{
    int n = G.size();
    vector<double> cost(n, 1e8);
    vector<bool> vis(n, false);
    vector<int> prev(n,-1);
    priority_queue<ArcP, vector<ArcP>, greater<ArcP>> Q;

    cost[s] = 0;
    Q.push(ArcP(0, s));

    while (not Q.empty())
    {
        int u = Q.top().second;
        Q.pop();
        if (not vis[u])
        {
            vis[u] = true;
            for (int i = 0; i < int(G[u].size()); ++i)
            {
                int v = G[u][i].second;
                int c = G[u][i].first;
                if (cost[v] > cost[u] + c)
                {
                    cost[v] = cost[u] + c;
                    prev[v] = u;
                    Q.push(ArcP(cost[v], v));
                }
            }
        }
    }

    if (cost[f] == 1e8) {cout << "no path from " << s << " to " << f << endl; return;}
    vector<int> l(1,f);
    while(f != s)
    {
        f = prev[f];
        l.push_back(f);
    }
    for(int i = int(l.size())-1; i >= 0 ;--i)
    {
        if(i != int(l.size())-1) cout << " ";
        cout << l[i];
    }
    cout << endl;
}

void read_graph(GrafP &G, int m)
{
    int x, y;
    double c;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> c;
        G[x].push_back({c,y});
    }
}

int main()
{
    int n, m, x, y;
    while(cin >> n >> m)
    {
        GrafP G(n);
        read_graph(G,m);
        cin >> x >> y;
        dijkstra(G,x,y);
    }
}
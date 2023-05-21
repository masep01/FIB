#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<double, int> ArcP; // arc amb pes
typedef vector< vector<ArcP> > GrafP; // graf amb pesos

double dijkstra(const GrafP &G, int s, int f)
{
    int n = G.size();
    vector<double> cost(n, 1e8);
    vector<bool> vis(n, false);

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
                    Q.push(ArcP(cost[v], v));
                }
            }
        }
    }
    return cost[f];
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
        double cost = dijkstra(G,x,y);
        if(cost == 1e8) cout << "no path from " << x << " to " << y << endl;
        else cout << cost << endl;
    }
}
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
    priority_queue<ArcP, vector<ArcP>, greater<ArcP>> Q;

    cost[s] = 0;
    Q.push(ArcP(0, s));

    while (not Q.empty())
    {
        int u = Q.top().second;
        int d = Q.top().first;
        Q.pop();
        if(u == f) {cout << cost[f] << endl; return;}
        if (d == cost[u])
        {
            for (ArcP x : G[u])
            {
                int v = x.second;
                double c = x.first;
                
                if (cost[v] > max(cost[u],c))
                {
                    cost[v] = max(cost[u],c);
                    Q.push(ArcP(cost[v], v));
                }
            }
        }
    }
    cout << 1e8 << endl;
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
    int n, m;
    while(cin >> n >> m)
    {
        GrafP G(n);
        read_graph(G,m);

        dijkstra(G,0,1);
    }
}
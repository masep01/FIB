#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> Arc;
typedef vector<vector<Arc>> Graph;
typedef vector<bool> vBool;

int n, m;
int A,B;
Graph M;
vector<int> costos;

void read_data()
{
    M = Graph(n);
    costos = vector<int>(n);
    for(int i = 0; i < n;++i) cin >> costos[i];
    int x,y,c;
    for(int i = 0; i < m;++i)
    {
        cin >> x >> y >> c;
        M[x].push_back({c,y});
        M[y].push_back({c,x});
    }
}

int dij()
{
    if(M[A].empty()) return 1e8;
    if(A==B) return 0;
    vBool vis(n,false);
    
    priority_queue<Arc, vector<Arc>, greater<Arc>> Q;
    Q.push({0,A});

    vector<int> dist(n,1e8);
    dist[A] = 0;

    while(not Q.empty())
    {
        int u = Q.top().second;
        Q.pop();

        if(not vis[u])
        {
            vis[u] = true;

            for(int i = 0; i < int(M[u].size()); ++i)
            {
                int y = M[u][i].second;
                int c = M[u][i].first;

                if(dist[y] > dist[u] + c + costos[y])
                {
                    dist[y] = dist[u] + c + costos[y];
                    Q.push({dist[y],y});
                }
            }
        }
    }
    return dist[B] - costos[B];
}

int main()
{
    cin >> n >> m;
    read_data();
    while(cin >> A >> B)
    {
        int cost = dij();
        cout << "c(" << A << "," << B << ") = ";
        if(cost > 100000) cout << "+oo" << endl;
        else cout << cost << endl;
    }
}

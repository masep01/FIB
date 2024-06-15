#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

typedef pair<int, int> P;
// El graf (connex) esta representat amb llistes d’adjacencia
// Els parells son (cost, vertex)
int mst(const vector<vector<P>> &g)
{ 
    int n = g.size();
    vector<bool> vis(n, false);
    vis[1] = true;
    priority_queue<P, vector<P>, greater<P>> pq;

    for (P x : g[1])  pq.push(x);
    int sz = 2;
    int sum = 0;
    while (sz < n)
    {
        int c = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if (not vis[x])
        {
            vis[x] = true;
            for (P y : g[x]) pq.push(y);
            sum += c;
            ++sz;
        }
    }
    return sum;
}

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        vector<vector<P>> G(n+1);
        int x,y,c;
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> c;
            G[x].push_back({c,y});
            G[y].push_back({c,x});
        }
        cout << mst(G) << endl;
    }


}
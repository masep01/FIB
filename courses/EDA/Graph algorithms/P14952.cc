#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

typedef vector<vector<int>> Graph;

list<int> ordenacio_topologica(Graph &G)
{
    int n = G.size();
    vector<int> ge(n, 0);
    for (int u = 0; u < n; ++u)
    {
        for (int v : G[u]) ++ge[v];
    }
    priority_queue<int, vector<int>, greater<int>> S;
    for (int u = 0; u < n; ++u)
    {
        if (ge[u] == 0) S.push(u);
    }

    list<int> L;
    while (not S.empty())
    {
        int u = S.top();
        S.pop();
        L.push_back(u);
        for (int v : G[u])
        {
            if (--ge[v] == 0) S.push(v);
        }
    }
    return L;
}

int main()
{
    int n, m;

    while (cin >> n)
    {
        Graph G(n);
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
        }

        list<int> l = ordenacio_topologica(G);
        for(auto it = l.begin(); it != l.end();++it)
        {
            if(it == l.begin()) cout << (*it);
            else cout << " " << (*it);
        }
        cout << endl;
    }
}
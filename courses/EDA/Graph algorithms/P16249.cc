#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

typedef vector<vector<int>> Graph;

vector<string> ordenacio_topologica(Graph &G, const vector<string> &alba, map<string, int> &map, vector<int> &ge)
{
    int n = G.size();

    priority_queue<string, vector<string>, greater<string>> S;
    for (int u = 0; u < n; ++u)
    {
        if (ge[u] == 0) S.push(alba[u]);
    }

    vector<string> L;
    while (not S.empty())
    {
        string u = S.top();
        S.pop();
        L.push_back(u);
        for (int v : G[map[u]])
        {
            if (--ge[v] == 0) S.push(alba[v]);
        }
    }
    return L;
}

int main()
{
    int n; 
    while(cin >> n)
    {
        map<string,int> m;
        vector<string> m2(n);
        string w;
        for (int i = 0; i < n; i++) 
        {
            cin >> w;
            m[w] = i;
            m2[i] = w;
        }

        int t;
        cin >> t;

        Graph G(n);
        vector<int> ge(n, 0);

        string x,y;
        for (int i = 0; i < t; i++) 
        {
            cin >> x >> y;
            G[m[x]].push_back(m[y]);
            ++ge[m[y]];
        }

        vector<string> L = ordenacio_topologica(G, m2, m, ge);
        if(L.size() != n) cout << "NO VALID ORDERING" << endl;
        else
        {
            for(auto i : L) cout << i;
            cout << endl;
        }
    }
}
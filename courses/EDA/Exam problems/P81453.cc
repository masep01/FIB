#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> Graph;

int n, m;
Graph G;

void read()
{
    G = Graph(n);
    int x,y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        G[x].push_back(y);
    }
    for (int i = 0; i < n; i++) sort(G[i].begin(), G[i].end());
    
}

vector<int> bfs()
{
    vector<int> L(n,-1);

    queue<int> Q;
    Q.push(0);

    vector<bool> vis(n, false);
    vis[0] = true;

    while(not Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if(u==n-1) return L;
            
        for (int w : G[u])
        {
            if (not vis[w])
            {
                Q.push(w);
                vis[w] = true;
                L[w] = u;
            }
        }
    }
    return L;
}

void print(const vector<int> &path)
{
    vector<int> c;
    for(int i = n-1;i!=-1; i=path[i])
    {
        c.push_back(i);
    }
    int r = c.size()-1;
    for (int i = r; i >=0; --i)
    {
        if(i!=r) cout << " ";
        cout << c[i];
    }
    cout << endl;
}

int main()
{
    while (cin >> n >> m)
    {
        read();
        print(bfs());
    }
}
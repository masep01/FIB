#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Map;
typedef vector<vector<bool>> mBool;
typedef pair<int,int> Pos;

vector<int> XMOVES = {-1, 0, 0, 1};
vector<int> YMOVES = {0, -1, 1, 0};

bool pos_ok(Pos p, const Map &G)
{
    return (p.first>=0 and p.second>=0 and p.first < int(G.size()) and p.second < int(G[0].size()));
}

bool check_target(Pos p, const Map &G)
{
    return (G[p.first][p.second] == 't');
}

int bfs(Map& G, Pos p) 
{
    if(not pos_ok(p,G)) return -1;

    int steps = 0;
    int nodes_left = 1;
    int nodes_next = 0;
    queue<Pos> Q;
    bool found = false;

    mBool vis(G.size(),vector<bool>(G[0].size()));
    
    Q.push(p);
    vis[p.first][p.second] = true;
    if(pos_ok(p,G) and check_target(p,G)) found = true;
    
    while((Q.size() > 0) and (not found))
    {
      p = Q.front(); Q.pop();
      if(check_target(p,G)) found = true;
      else 
      {
        for(int i = 0; i < 4; ++i)
        {
          int x1 = p.first + XMOVES[i];
          int y1 = p.second + YMOVES[i];
          if(pos_ok({x1,y1}, G) and (not vis[x1][y1]) and G[x1][y1] != 'X')
          {
            Q.push({x1,y1});
            vis[x1][y1] = true;
            ++nodes_next;
          }
        }
        --nodes_left;
        if(nodes_left==0)
        {
          nodes_left = nodes_next;
          nodes_next = 0;
          ++steps;
        }
      }
    }
    if(found) return steps;
    else return -1;
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        Map G(n, vector<char>(m));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) cin >> G[i][j];  
        
        int x, y;
        cin >> x >> y;
        int d = bfs(G,{x-1, y-1});
        if(d != -1) cout << "distancia minima: " << d << endl;
        else cout << "no es pot arribar a cap tresor" << endl;
    }
}
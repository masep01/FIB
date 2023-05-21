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

int bfs(Map& G, Pos p) 
{
    int best = -1;
    queue<Pos> Q;
    vector<vector<int>> dist(G.size(),vector<int>(G[0].size(),-1));
    dist[p.first][p.second] = 0;
    Q.push(p);
    while(not Q.empty())
    {
        p = Q.front(); Q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int x1 = p.first + XMOVES[i];
            int y1 = p.second + YMOVES[i];
            if(pos_ok({x1,y1}, G) and (dist[x1][y1]==-1) and G[x1][y1] != 'X')
            {
                Q.push({x1,y1});
                dist[x1][y1] = dist[p.first][p.second] +1;
                if(G[x1][y1] == 't') best = dist[x1][y1];
            }
        }
    }
    return best;
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
        if(d != -1) cout << "distancia maxima: " << d << endl;
        else cout << "no es pot arribar a cap tresor" << endl;
    }
}
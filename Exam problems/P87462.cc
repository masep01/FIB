#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<char>> M;
typedef pair<int,int> Pos;

vector<Pos> VDIRS = {{1,0},{0,1},{-1,0},{0,-1}};
vector<Pos> VDIRS2 = {{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{-1,1},{1,1},{1,-1}};

bool pos_ok(Pos p)
{
    return p.first >= 0 and p.first < n and p.second >= 0 and p.second < m;
}

bool invalid(Pos p)
{
    int x = p.first;
    int y = p.second;

    if(M[x][y] == 'X' or 
       M[x][y] == 'F') return true;

    for(int i = 0; i < 8; ++i)
    {
        x = p.first  + VDIRS2[i].first;
        y = p.second + VDIRS2[i].second;
        if(M[x][y] == 'F') return true;
    }
    return false;
}

bool bfs(Pos p)
{
    if(invalid(p)) return false;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<Pos> Q;
    Q.push(p);

    while(not Q.empty())
    {
        p = Q.front();
        Q.pop();
        
        if(M[p.first][p.second] == 'B') return true;
    
        for (int i = 0; i < 4; i++)
        {
            Pos d = p;
            d.first  += VDIRS[i].first;
            d.second += VDIRS[i].second;
            if(not vis[d.first][d.second] and pos_ok(d) and not invalid(d)) 
            {
                vis[d.first][d.second] = true;
                Q.push(d);
            }
        }
    }
    return false;
}


int main()
{
    while(cin >> n >> m)
    {
        M = vector<vector<char>>(n, vector<char>(m));
        Pos p;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++) 
            {
                cin >> M[i][j];
                if(M[i][j] == 'P') p = Pos(i,j);
            }
        }
        if(bfs(p)) cout << "si" << endl;
        else cout << "no" << endl;  
    }      
}
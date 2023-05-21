#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> Pos;

int n, m;
Pos ini, fin;
vector<vector<char>> M;
vector<Pos> MOVES = {{1,0},{-1,0},{0,-1},{0,1}};

void read()
{
    M = vector<vector<char>>(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> M[i][j];
            if(M[i][j] == 'I') ini = {i,j};
            if(M[i][j] == 'F') fin = {i,j};
        } 
    }  
}

bool pos_ok(Pos p)
{
    return p.first >= 0 and p.first < n and p.second >= 0 and p.second < m;
}

bool monster(Pos p)
{
    if(M[p.first][p.second] == 'M') return true;
    for(auto d : MOVES)
    {
        int x = p.first + d.first;
        int y = p.second + d.second;
        if(pos_ok({x,y}) and M[x][y] == 'M') return true;
    }
    return false;
}

bool equ_pos(Pos p1, Pos p2)
{
    return p1.first == p2.first and p1.second == p2.second;
}

void bfs()
{
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vis[ini.first][ini.second] = true;

    queue<Pos> Q;
    Q.push(ini);

    while (not Q.empty())
    {
        Pos p = Q.front();
        Q.pop();

        if(equ_pos(p,fin)) {cout << "SI" << endl; return;}
        for(auto d : MOVES)
        {
            Pos x = p;
            x.first += d.first;
            x.second += d.second;
            
            if(pos_ok(x) and not vis[x.first][x.second] and not monster(x))
            {
                vis[x.first][x.second] = true;
                Q.push(x);
            }
        }
    }
    cout << "NO" << endl;
}

int main()
{
    while(cin >> n >> m)
    {
        read();
        bfs();
    }
}
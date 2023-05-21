#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> Pos;
typedef vector<vector<bool>> mBool;
typedef vector<bool> vBool;

int n, m;
vector<vector<char>> M;

queue<Pos> qCavalls;
queue<Pos> qAlfils;
mBool bCavalls;
mBool bAlfils;

vector<Pos> CAVALL = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
vector<Pos> ALFIL = {{-1,-1},{-1,1},{1,1},{1,-1}};

void read_data()
{
    M = vector<vector<char>>(n, vector<char>(m));
    bCavalls = mBool(n, vBool(m,false));
    bAlfils = mBool(n, vBool(m,false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> M[i][j];
            if(M[i][j] == 'K') qCavalls.push(Pos(i,j));
            if(M[i][j] == 'B') qAlfils.push(Pos(i,j));
        }
    }
}

bool pos_ok(Pos p)
{
    return p.first >= 0 and p.first < n and p.second >= 0 and p.second < m;
}

bool trap(Pos p)
{
    return M[p.first][p.second] == 'T';
}

bool coin(Pos p)
{
    return M[p.first][p.second] >= '0' and M[p.first][p.second] <= '9';
}

int dfs(Pos x, mBool &vis, const vector<Pos> &MOVES)
{
    vis[x.first][x.second] = true;
    int sum = 0;
    
    for (int i = 0; i < int(MOVES.size()); i++)
    {
        Pos p = x;
        p.first += MOVES[i].first;
        p.second += MOVES[i].second;

        if(pos_ok(p) and not vis[p.first][p.second] and not trap(p)) sum += dfs(p,vis,MOVES); 
    }
    
    if(coin(x)) 
    {
        sum += (M[x.first][x.second] - '0');
        M[x.first][x.second] = '.';   
    }
    return sum;
}

void play()
{
    int sum = 0;
    
    while(not qCavalls.empty())
    {
        Pos p = qCavalls.front();
        if(not bCavalls[p.first][p.second]) sum += dfs(p,bCavalls,CAVALL);
        qCavalls.pop();
    }
    while(not qAlfils.empty())
    {
        Pos p = qAlfils.front();
        if(not bAlfils[p.first][p.second]) sum += dfs(p,bAlfils,ALFIL);
        qAlfils.pop();
    }
    cout << sum << endl;
}

int main()
{
    while(cin >> n >> m)
    {
        read_data();
        play();
    }      
}
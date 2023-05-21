#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> Pos;


int n,m;
vector<vector<char>> M;
vector<Pos> CAVALL = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
Pos ini;

void read_data()
{
    M = vector<vector<char>>(n, vector<char>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> M[i][j]; 
    
    cin >> ini.first >> ini.second;
    --ini.first;
    --ini.second;
}

bool pos_ok(Pos p)
{
    return p.first >= 0 and p.first < n and p.second >= 0 and p.second < m and M[p.first][p.second] != 'X';
}

int bfs()
{
    vector<vector<int>> dist(n, vector<int>(m,-1));
    dist[ini.first][ini.second] = 0;
    queue<Pos> Q;
    Q.push(ini);

    bool f = false;
    while(not Q.empty() and not f)
    {
        Pos p = Q.front();
        Q.pop();
        if(M[p.first][p.second] == 'p') return dist[p.first][p.second];
    
        for(auto d : CAVALL)
        {
            Pos u = p;
            u.first += d.first;
            u.second += d.second;

            if(pos_ok(u) and dist[u.first][u.second] == -1)
            {
                dist[u.first][u.second] = dist[p.first][p.second]+1;
                Q.push(u);
            }
        }
        
    }
    return -1;
}

int main()
{
    while(cin >> n >> m)
    {
        read_data();
        int x = bfs();

        if(x == -1) cout << "no" << endl; 
        else cout << x << endl; 

    }
}
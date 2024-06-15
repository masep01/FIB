#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Graph;
typedef pair<int,int> Pos;
int n, m;
Graph M;
queue<Pos> QQ;
vector<Pos> VDIRS = {{1,0},{0,1},{-1,0},{0,-1}};

void read_graph()
{
    M = Graph(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> M[i][j];
            if(M[i][j]!='.' and M[i][j]!='#') QQ.push({i,j});
        } 
    } 
}

bool pos_ok(Pos p)
{
    return p.first >= 0 and p.first < n and p.second >= 0 and p.second < m and M[p.first][p.second]=='.';
}

void bfs(Pos p)
{
    queue<Pos> Q;
    Q.push(p);

    while(not Q.empty())
    {
        p = Q.front();
        Q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            Pos d = p;
            d.first  += VDIRS[i].first;
            d.second += VDIRS[i].second;
            if(pos_ok(d)) 
            {
                M[d.first][d.second] = M[p.first][p.second];
                Q.push(d);
            }
        }
    }
}

void print_map()
{
    while(not QQ.empty())
    {
        bfs(QQ.front());
        QQ.pop();
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) cout << M[i][j];
        cout << endl;
    }
    cout << endl;
}

int main()
{
    while (cin >> n >> m)
    {
        read_graph();
        print_map();
    }
}
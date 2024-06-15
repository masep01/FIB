#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Map;
typedef pair<int,int> Pos;
typedef vector<vector<bool>> mBool;

int n,m;
vector<Pos> MOVES = {{0,-1}, {1,0}, {0,1}, {-1,0}};

bool pos_ok(Pos p,const Map& G)
{
    int x1 = p.first;
    int y1 = p.second;
    return x1>=0 and y1>=0 and x1 < int(G.size()) and y1 < int(G[0].size());
}


void print_path(const vector<Pos> &path, const Map& G)
{
    for (int i = 0; i < int(path.size()); i++) 
    {
        cout << G[path[i].first][path[i].second];
    }
    cout << endl;
}


void bfs(const Map& G,Pos obj, vector<Pos> &path, mBool &vis) 
{
    Pos p = path.back();

    if(p == obj) print_path(path, G);
    else
    {
        for(int i = 0; i<4; ++i)
        {
            Pos u = p;
            u.first += MOVES[i].first;
            u.second += MOVES[i].second;

            if(pos_ok(u,G) and not vis[u.first][u.second])
            {        
                vis[u.first][u.second] = true;
                path.push_back(u);

                bfs(G,obj,path,vis);

                path.pop_back(); 
                vis[u.first][u.second] = false;  
            }
        }
    }    
}

int main()
{
    cin >> n >> m;
    Map G(n, vector<char>(m));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) cin >> G[i][j]; 

    Pos ini;
    Pos obj;
    cin >> ini.first >> ini.second;
    cin >> obj.first >> obj.second;

    mBool vis(n, vector<bool>(m, false));
    vector<Pos> path;

    vis[ini.first][ini.second] = true;
    path.push_back(ini);
    
    bfs(G,obj,path,vis);
}
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef pair<int,int> Pos;
typedef vector<vector<char>> Mapa;

vector<Pos> MOVES = {{0,1},{0,-1},{-1,0},{1,0}};
int n,m;
Mapa M;

// Llegim l'input.
void llegir_mapa()
{
    cin >> n >> m;
    M = Mapa(n, vector<char>(m));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) cin >> M[i][j];
    
}

// Torna true si la posicio p es troba dins del tauler i no es un obstacle, false altrament.
bool pos_ok(Pos p)
{
    int x = p.first;
    int y = p.second;
    return x < n and y < m and x >= 0 and y >= 0 and M[x][y] != 'X';
}

// Torna la segona distància màxima a un tresor 't' des de la posició p, -1 si no pot arribar a dos tresors o més.
int bfs(Pos p)
{
    // BFS (cerca en amplada)

    queue<Pos> Q;
    Q.push(p);

    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[p.first][p.second] = 0;


    int primer = 0;     // Màxima distància
    int segon = 0;      // Segona distància màxima
    int c = 0;          // Comptador dels tresors trobats

    while(not Q.empty())
    {
        p = Q.front();
        Q.pop();
        
        // Si trobem un tresor actualitzem les distàncies màximes
        if(M[p.first][p.second] == 't')
        {
            int d = dist[p.first][p.second];
            if(d > primer)
            {
                segon = primer;
                primer = d;
            }
            else if (d > segon) segon = d;
            ++c;
        }

        for(auto d : MOVES)
        {
            int x = p.first + d.first;
            int y = p.second + d.second;

            if(pos_ok({x,y}) and dist[x][y] == -1)
            {
                dist[x][y] = dist[p.first][p.second] + 1;
                Q.push({x,y});
            }
        }
    }

    if(c < 2) return -1;
    else return segon;
}

int main()
{
    llegir_mapa();

    int x,y;
    cin >> x >> y;
    --x; --y;

    int dist = bfs({x,y});
    
    if(dist == -1) cout << "no es pot arribar a dos o mes tresors" << endl;
    else cout << "segona distancia maxima: " << dist << endl;
}
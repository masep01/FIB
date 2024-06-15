#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> Pos;
typedef vector<int> VInt;
typedef vector<VInt> MInt;
typedef vector<string> VString;
typedef vector<VString> MString;

vector<int> MOVESX = {0,0,1,-1};
vector<int> MOVESY = {1,-1,0,0};

bool pos_ok(const MString &buscador, Pos p)
{
    int n = buscador.size();
    int m = buscador[0].size();
    int i = p.first;
    int j = p.second;
    return (i >= 0) and (j >= 0) and (i < n) and (j < m) and (buscador[i][j] != "*");
}

pair<int, Pos> BFS(const MString &buscador, Pos source, string target)
{
    int x = source.first;
    int y = source.second;
    if(buscador[x][y] == target) return {0,{x,y}};

    int n = buscador.size();
    int m = buscador[0].size();
    MInt dist(n, VInt(m,-1));
    dist[x][y] = 0;

    queue<Pos> Q;
    Q.push({x,y});

    while(not Q.empty())
    {
        Pos p = Q.front();
        Q.pop();
        if(buscador[p.first][p.second] == target) return {dist[p.first][p.second], p};
        for (int i = 0; i < 4; i++)
        {
            Pos new_p = {p.first+MOVESX[i], p.second+MOVESY[i]};
            
            if(pos_ok(buscador,new_p) and dist[new_p.first][new_p.second] == -1)
            {
                dist[new_p.first][new_p.second] = dist[p.first][p.second]+1;
                Q.push(new_p);
            }
        }
    }
    return {-1,{-1,-1}};

}

int search_words(const VString &vParaules, const MString &buscador)
{
    int cont = 0;
    Pos p = {0,0};
    for (int i = 0; i < int(vParaules.size()); i++)
    {
        pair<int,Pos> m = BFS(buscador, p, vParaules[i]);
        p = m.second;
        if(m.first == -1) return -1;
        cont += m.first+1;
    }
    return cont;
}

int main()
{
    int n,m,p;
    while(cin >> n >> m)
    {
        MString buscador(n, VString(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++) cin >> buscador[i][j];
        }

        cin >> p;
        VString paraules(p);
        for (int i = 0; i < p; i++) cin >> paraules[i];
        
        int x = search_words(paraules, buscador);
        if(x==-1) cout << "impossible" << endl;
        else cout << x << endl;
    }
}
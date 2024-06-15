#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> Pos;
typedef vector<Pos> VPos;
typedef vector<int> VInt;
typedef vector<VInt> MInt;
typedef vector<string> VString;
typedef vector<VString> MString;

int N, M, W, L;

VPos Dirs = {{1,2}, {-1,2}, {2,1}, {-2,1}, {2,-1}, {-2,-1}, {1,-2}, {-1,-2}};

bool pos_ok(Pos p)
{
    int i = p.first;
    int j = p.second;
    return (i >= 0) and (j >= 0) and (i < N) and (j < M);
}

int BFS(Pos source, Pos target)
{
    if(source == target) return 0;

    MInt punts(N, VInt(M,-1));
    punts[source.first][source.second] = 0;

    queue<Pos> Q;
    Q.push(source);

    while(not Q.empty())
    {
        Pos p = Q.front();
        Q.pop();

        if(p == target) return punts[p.first][p.second];
        for (int i = 0; i < 8; i++)
        {
            Pos new_p = {p.first + Dirs[i].first, p.second + Dirs[i].second};
            
            if(pos_ok(new_p) and punts[new_p.first][new_p.second] == -1)
            {
                punts[new_p.first][new_p.second] = punts[p.first][p.second]+1;
                Q.push(new_p);
            }
        }
    }
    return -1;
}

int max_pts(const VPos &OBJ)
{
    int cont = 0;
    int best = 0;
    Pos p = {0,0};
    for (int i = 0; i < int(OBJ.size()); i++)
    {
        int b = BFS(p,OBJ[i]);
        if(b!=-1) cont += W - b*L;
        else return best;
        p = OBJ[i];
        if(best < cont) best = cont;
    }
    return best;
}

int main()
{
    int k;
    while(cin >> N >> M >> W >> L >> k)
    {
        VPos objectius(k);
        for (int i = 0; i < k; i++) cin >> objectius[i].first >> objectius[i].second;
        cout << max_pts(objectius) << endl;
    }
}
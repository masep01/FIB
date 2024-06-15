#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

typedef struct  
{
    double i;
    double j;
    double radi;
}Roca;

typedef vector<Roca> Riu;

bool jump(Roca r0, Roca r, double d) { 
    
    double c1 = r0.j - r.j; 
    double c2 = r0.i - r.i;

    double d_jump = sqrt(c1 * c1 + c2 * c2) - (r0.radi + r.radi);

    if (d_jump < d) return true; 
    return false;
}

int BFS(const Riu &M, double s)
{
    queue<pair<Roca,int>> Q;
    Q.push({M[0],0});

    int n = M.size();

    vector<int> D(n,-1);
    D[0] = 0;

    while(not Q.empty())
    {
        Roca R = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for (int i = 0; i < n; i++)
        {
            if(jump(R, M[i], s) and D[i] == -1)
            {
                Q.push({M[i],i});
                D[i] = D[x]+1;
                if(i == n-1) return D[i];
            }
        } 
    }
    return -1;
}

int main()
{
    int r;
    double d;
    while(cin >> r >> d)
    {
        Riu mapa(r);
        for (int i = 0; i < r; i++) cin >> mapa[i].i >> mapa[i].j >> mapa[i].radi;
        int s = BFS(mapa,d);
        if(s == -1) cout << "Xof!" << endl;
        else cout << s << endl;
    }
    
}
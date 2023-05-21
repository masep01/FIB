#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Map;
typedef pair<int,int> Pos;

vector<int> XMOVES = {-1, 0, 0, 1};
vector<int> YMOVES = {0, -1, 1, 0};

int dfs(Map& G, int x, int y) 
{
    int l = 0;
    queue<Pos> cua;
    cua.push(make_pair(x,y));

    while(not cua.empty())
    {
        Pos p = cua.front();
        cua.pop();

        for(int i = 0; i<4; ++i)
        {
            int x1 = p.first + XMOVES[i];
            int y1 = p.second + YMOVES[i];

            if(x1>=0 and y1>=0 and x1 < G.size() and y1 < G[0].size())
            {        
                if(G[x1][y1] == 't')
                {
                    G[x1][y1] = 'X';
                    cua.push(make_pair(x1,y1));
                    ++l;
                }
                if(G[x1][y1] == '.') 
                {
                    G[x1][y1] = 'X';
                    cua.push(make_pair(x1,y1));
                }
            }
        }
    }
    return l;
}

int main()
{
    int n,m;
    while(cin >> n >> m){
        Map G(n, vector<char>(m));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) 
                cin >> G[i][j];  
        
        int x, y;
        cin >> x >> y;
        cout << dfs(G,x-1, y-1) << endl;
    }
}
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef pair<int, int> Pos;
typedef vector<vector<int>> Mat;
typedef vector<vector<bool>> BMat;

const int inf = numeric_limits<int>::max();

const vector<pair<int, int>> dirs = {{0,-1}, {0, 1}, {1, 0}, {-1, 0}};

bool on_border(Pos c, int n)
{
    return c.first == 0 or c.second == 0 or c.first == n-1 or c.second == n-1;
}

int cost(Mat &M)
{
    int n = M.size();
    Pos p = {n / 2, n / 2};
    Mat dist(n, vector<int>(n, inf));
    BMat used(n, vector<bool>(n, false));

    priority_queue<pair<int, Pos>, vector<pair<int, Pos>>, greater<pair<int, Pos>>> Q;

    dist[p.first][p.second] = M[p.first][p.second];
    Q.push({dist[p.first][p.second], p});

    while (not Q.empty())
    {
        Pos c = Q.top().second;
        Q.pop();
        
        if (not used[c.first][c.second])
        {
            used[c.first][c.second] = 1;
            if (on_border(c, n)) return dist[c.first][c.second];
            
            for (auto &d : dirs)
            {
                Pos k = {c.first + d.first, c.second + d.second};
                int x = k.first;
                int y = k.second;

                if (dist[c.first][c.second] + M[x][y] < dist[x][y])
                {
                    dist[x][y] = dist[c.first][c.second] + M[x][y];
                    Q.push({dist[x][y], k});
                }
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    while (cin >> n)
    {
        Mat M(n, vector<int>(n));
        for (int i = 0; i < n; ++i)           
        {
            for (int j = 0; j < n; ++j) cin >> M[i][j];
        }
        cout << cost(M) << endl;
    }
}
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int MIN_ELO = 1200;
typedef pair<int, bool> Player;

bool comp(pair<int, string> p1, pair<int, string> p2)
{
    if(p1.first != p2.first) return p1.first > p2.first;
    else return p1.second < p2.second;
}

bool get_con(map<string, Player> &m, string p)
{
    auto it = m.find(p);
    if(it != m.end()) return it->second.second;
    return false;
}

void login(map<string, Player> &m, string p)
{
    map<string, Player>::iterator it = m.find(p);
    if(it == m.end())
    {
        m[p] = make_pair(MIN_ELO, true);
    }
    else (it->second).second = true;
}

void logout(map<string, Player> &m, string p)
{
    map<string, Player>::iterator it = m.find(p);
    if(it != m.end()) it->second.second = false;
}

void play(map<string, Player> &m, string p1, string p2)
{
    if(get_con(m, p1) and get_con(m, p2))
    {
        m[p1].first += 10;
        if(m[p2].first > 1200) m[p2].first -= 10;
    }
    else cout << "jugador(s) no connectat(s)" << endl;
}

void get_elo(map<string, Player> &m, string p)
{
    cout << p << " " << m[p].first << endl;
}

void print_rank(map<string, Player> &m)
{
    if(not m.empty())
    {
        cout << endl;
        cout << "RANKING" << endl;
        vector<pair<int, string>> v(m.size());
        int i = 0;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            v[i] = (make_pair(it->second.first, it->first));
            ++i;
        }
        sort(v.begin(), v.end(), comp);
        for (int j = 0; j < v.size(); ++j)
        {
            cout << v[j].second << " " << v[j].first << endl;
        }
    }
}

int main()
{
    map<string, Player> m;
    string cmd;

    while(cin >> cmd)
    {
        if(cmd == "LOGIN")
        {
            string p;
            cin >> p;
            login(m, p);
        }
        else if(cmd == "LOGOUT")
        {
            string p;
            cin >> p;
            logout(m, p);
        }
        else if(cmd == "PLAY")
        {
            string p1, p2;
            cin >> p1 >> p2;
            play(m, p1, p2);
        }
        else if(cmd == "GET_ELO")
        {
            string p;
            cin >> p;
            get_elo(m, p);
        }
    }
    print_rank(m);
}
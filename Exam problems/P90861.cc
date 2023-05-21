#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

int n;

void print_cues(vector<queue<string>> &V)
{
    cout << endl;
    cout << "CONTINGUTS FINALS" << endl;
    cout << "-----------------" << endl;
    for(int i = 0; i < n; ++i)
    {
        cout << "cua " << i+1 << ":";
        while(not V[i].empty()) {cout << " " << V[i].front(); V[i].pop();}
        cout << endl;  
    }
}

void read_super(vector<queue<string>> &V)
{
    string w, nom;
    getline(cin, w);
    for (int i = 0; i < n; i++)
    {
        getline(cin, w);
        istringstream s(w);
        while(s >> nom) V[i].push(nom);
    }
    getline(cin, w);
}

void check_queues(vector<queue<string>> &V)
{
    string w, nom;
    int p;

    cout << "SORTIDES" << endl;
    cout << "--------" << endl;

    while (cin >> w)
    {
        if(w == "SURT")
        {
            cin >> p; --p;
            if(p < n and p>= 0 and not V[p].empty())
            {
                cout << V[p].front() << endl;
                V[p].pop();
            }
        }
        if(w == "ENTRA") 
        {
            cin >> nom >> p; --p;
            if(p>=0 and p<n) V[p].push(nom);
        }
    }
}

int main()
{
    cin >> n;
    vector<queue<string>> V(n);
    read_super(V);
    check_queues(V);
    print_cues(V);
}
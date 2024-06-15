#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

void info(map<string, string> &P)
{
    cout << "PARELLES:" << endl;
    for (auto it = P.begin(); it != P.end(); it++)
    {
        if(it->second != "" and it->first < it->second)
            cout << it->first << " " << it->second << endl;
    }
    cout << "SOLS:" << endl;
    for (auto it = P.begin(); it != P.end(); it++)
    {
        if(it->second == "")
            cout << it->first << endl;
    }
    cout << "----------" << endl;
}


void manage_couple(string p1, string p2, map<string, string> &P)
{
    if(P[p1] != "") P[P[p1]] = "";
    if(P[p2] != "") P[P[p2]] = "";
    P[p1] = p2;
    P[p2] = p1;
}

int main()
{
    map<string, string> P;

    string w, p1, p2;

    while(cin >> w)
    {
        if(w == "liats")
        {
            cin >> p1 >> p2;
            manage_couple(p1, p2, P);
        }
        else if(w == "info") info(P);
    }
}


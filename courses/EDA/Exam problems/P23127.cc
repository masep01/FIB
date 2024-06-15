#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n; 
    while(cin >> n)
    {
        map<string, string> m;
        string w,a;
        for (int i = 0; i < n; i++)
        {
            cin >> w >> a;
            m[a] = w;
        }

        cin >> n;
        map<pair<string,string>, bool> vots;
        string autor,vot,prop;
        for (int i = 0; i < n; i++)
        {
            cin >> autor >> vot >> prop;
            if(vot == "SI") vots[{autor,prop}] = true;
            else vots[{autor,prop}] = false;
        }
        
        map<string,pair<int,int>> punts;
        for(auto it = vots.begin(); it != vots.end(); ++it)
        {
            string prop = it->first.second;
            if(it->second) ++punts[prop].first;
            else ++punts[prop].second;
        }
        
        for (auto it = punts.begin(); it != punts.end(); it++)
        {
            if(it->second.first > it->second.second)
            {
                cout << it->first << ", de " << m[it->first] << ", que ha guanyat ";
                cout << it->second.first << "-" << it->second.second << endl;
            }
        }
        cout << "----------" << endl;
    }
    
}
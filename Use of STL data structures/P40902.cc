#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> m;
    string name, cmd;
    int val;
    while(cin >> name)
    {
        cin >> cmd;
        if(cmd == "leaves")
        {
            if(m.find(name) == m.end()) cout << name << " is not in the casino" << endl;
            else
            {
                cout << name << " has won " << m.find(name)->second << endl;
                m.erase(name);
            }
        }
        else if(cmd == "enters")
        {
            if(m.find(name) != m.end()) cout << name << " is already in the casino" << endl;
            else 
            {
                m.insert(make_pair(name, 0)); 
            }
        }
        else if(cmd == "wins")
        {
            if(m.find(name) == m.end()) 
            {
                cout << name << " is not in the casino" << endl;
                cin >> val;
            }
            else
            {
                cin >> val;
                m[name] += val;
            }
        }
    }
    cout << "----------" << endl;
    for(map<string, int>::const_iterator it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << " is winning " << it->second << endl;
    }
}
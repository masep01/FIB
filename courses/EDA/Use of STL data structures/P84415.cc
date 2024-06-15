#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> m;
    string w;

    while (cin >> w)
    {
        if(w == "minimum?")
        {
            if(m.empty()) cout << "indefinite minimum" << endl;
            else
            {
                auto it = m.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else if(w == "maximum?")
        {
            if(m.empty()) cout << "indefinite maximum" << endl;
            else
            {
                auto it = m.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else if(w == "store" or w == "delete")
        {
            string p; 
            cin >> p;

            auto it2 = m.find(p);
            if(w == "store")
            {
                if(it2 == m.end()) m.insert(make_pair(p,1));
                else ++it2->second;
            }
            else if(it2 != m.end())
            {
                if(it2->second <= 1) m.erase(p);
                else --it2->second;
            }
        }
    }
}

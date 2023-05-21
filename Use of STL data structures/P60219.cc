#include <iostream>
#include <set>
using namespace std;

struct mycomp
{
    bool operator() (const string &s1, const string &s2) const
    {
        if(s1.size() != s2.size()) return s1.size() < s2.size();
        return s1 < s2;
    }
};

int main()
{
    string w;
    int count = 1;
    set<string>::iterator it1;
    set<string, mycomp>::iterator it2;

    while (w != "QUIT")
    {
        set<string> has;
        set<string, mycomp> had;
        while(cin >> w and w != "END" and w != "QUIT")
        {
            it1 = has.find(w);
            if(it1 == has.end()) 
            {
                has.insert(it1, w);
                it2 = had.find(w);
                if(it2 != had.end()) had.erase(it2);
            }
            else
            {
                it2 = had.begin();
                had.insert(it2, *it1);
                has.erase(it1);
            }
            
        }
        if(count > 1) cout << endl;
        cout << "GAME #" << count << endl;
        cout << "HAS:" << endl;
        for (auto it1 = has.begin(); it1 != has.end(); it1++) cout << *it1 << endl;
        cout << endl << "HAD:" << endl;
        for (auto it2 = had.begin(); it2 != had.end(); it2++) cout << *it2 << endl;
        ++count;
    }
}
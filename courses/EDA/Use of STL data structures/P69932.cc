#include <iostream>
#include <set>
#include <sstream>
using namespace std;

int main()
{
    string w;
    while(getline(cin, w))
    {
        istringstream word(w);
        int x;
        set<int> s;
        while(word >> x) s.insert(x);

        set<int>::iterator it = s.begin();

        int ant, c = 0;
        if(not s.empty())
        {
            ant = *it;
            ++it; 
            ++c;
        }
        for (; it != s.end(); it++)
        {
            if((ant < *it) and
                ((*it%2 == 0 and ant%2 == 1) or (*it%2 == 1 and ant%2 == 0))) 
            {
                ++c;
            }
            ant = *it;
            
        }
        
        cout << c << endl;

    }
}
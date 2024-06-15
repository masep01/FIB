#include <iostream>
#include <map>
using namespace std;

int main()
{
    
    int x,y,n,c;
    while(cin >> x >> y >> n)
    {
        map<int, int> m;
        bool found = false;
        int c = 0;
        m[n] = 0;

        while(n <= 100000000 and not found)
        {
            ++c;
            if(n%2 == 0) n = n/2 + x;
            else n = 3*n + y;

            if(m.find(n) != m.end()) found = true;
            else m[n] = c;
        }

        if(found) cout << m.size() - m.find(n)->second << endl;
        else cout << n << endl;
    }
}
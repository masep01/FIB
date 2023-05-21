#include <iostream>
#include <map>
using namespace std;



int main()
{
    int n, j;
    string w;
    while(cin >> n)
    {
        map<string, int> M;
        int total = n;
        for (int i = 0; i < n; i++)
        {
            cin >> w;
            ++M[w];
        }
        
        cin >> j;
        for (int i = 0; i < j; i++)
        {
            cin >> w;
            auto it = M.find(w);
            if(it == M.end()) 
            {
                M.insert({w,1});
                ++total;
            }
            else    
            {
                int x = it->second;
                if(x+1 <= total-x) 
                {
                    ++it->second;
                    ++total;
                }
            }
        }
        auto it = M.begin();
        while(it!=M.end()) 
        {
            cout << it->first << " " << it->second << endl;
            ++it;
        }
        cout << "--------------------" << endl;
    }
}

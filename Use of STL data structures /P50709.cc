#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> s;
    char cmd;

    while(cin >> cmd)
    {
        if(cmd == 'S')
        {
            int n;
            cin >> n;
            s.push(n);
        }
        else
        {
            if(s.empty()) 
            {
                cout << "error!" << endl;
                if(cmd == 'I' or cmd == 'D')
                {
                    int n;
                    cin >> n;
                }
            }
            else if(cmd == 'A') cout << s.top() << endl;
            else if(cmd == 'R') s.pop();
            else if(cmd == 'I')
            {
                int n;
                cin >> n;
                n += s.top();
                s.pop();
                s.push(n); 
            }
            else if(cmd == 'D')
            {  
                int n;
                cin >> n;
                n = s.top() - n;
                s.pop();
                s.push(n);
            }
            else s.pop();
        }
    }   
}
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(4);

    priority_queue<int, vector<int>, greater<int>> s;
    string w;
    int n, max = 0;
    double sum = 0;
    
    while(cin >> w)
    {
        if(w == "number")
        {
            cin >> n;
            if(s.empty() or n > max) max = n;
            sum += n;
            s.push(n);
        }
        else if(w == "delete" and not s.empty())
        {
            sum -= s.top();
            s.pop();
            
        }
        if(s.empty()) cout << "no elements" << endl;
        else 
        {
            cout << "minimum: " << s.top();
            cout << ", maximum: " << max;
            cout << ", average: " << sum/s.size() << endl;
        }

    }
}
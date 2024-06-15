#include <iostream>
#include <vector>
using namespace std;

int s, p;

void escriu(const vector<string> &V, vector<int> &sol)
{
    for(int k = 0; k < p; ++k)
    {
        string a = "";
        cout << "subconjunt " << k+1 << ": {";
        for (int i = 0; i < s; i++) 
        {
            if(sol[i] == k)
            {
                cout << a << V[i];
                a = ",";
            }
        }
        cout << "}" << endl;
    }
    cout << endl;
}

void subj(int i, vector<string> &V, vector<int> &sol)
{
    if(i == s) escriu(V,sol);
    else
    {
        for (int j = 0; j < p; j++)
        {
            sol[i] = j;
            subj(i+1,V,sol);
        }
        
    }
}

int main()
{
    cin >> s;
    vector<string> P(s);
    vector<int> sol(s);
    for (int i = 0; i < s; i++) cin >> P[i];
    cin >> p;
    subj(0,P,sol);

}
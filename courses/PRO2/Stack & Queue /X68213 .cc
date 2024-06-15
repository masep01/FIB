#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

void print_stack(stack<string> p){
    while(not p.empty()){
        cout << p.top() << endl;
        p.pop();
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;

    vector<stack<string>> biblio(n);
    
    cin >> n;
    while(n != -4){
        if(n == -1){
            string title;
            cin >> title >> n;
            biblio[n-1].push(title);
        }
        else if(n == -2){
            int amount;
            cin >> amount >> n;
            for(int i = 0; i < amount; ++i) biblio[n-1].pop();
        }
        else {
            cin >> n;
            cout << "Pila de la categoria " << n << endl;
            print_stack(biblio[n-1]);
        }
        cin >> n;
    }

}
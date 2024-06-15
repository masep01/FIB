#include <iostream>
#include <stack>
using namespace std;

int main(){
  stack<int> pila;
  int n;
  cin >> n;
  int m = n/2;
  int x;

  for (int i = 0; i < m; i++){
    cin >> x;
    pila.push(x);
  }
  bool pal = true;

  if(n%2 != 0) cin >> x;

  while(pal and not pila.empty()){
    cin >> x;
    if(pila.top() == x)  pila.pop();
    else pal = false;
  }

  if(pal) cout << "SI" << endl;
  else cout << "NO" << endl;

}

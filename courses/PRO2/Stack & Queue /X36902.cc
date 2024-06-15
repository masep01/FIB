#include <iostream>
#include <stack>
using namespace std;

bool correct(){
  stack<char> p;
  char c;
  cin >> c;

  while(c != '.'){
    if(p.empty() and (c == ')' or c == ']')) return false;

    if(c == '[' or c == '(') p.push(c);
    else if(c == ')') {
      if(p.top() == '(') p.pop();
      else if(p.top() == '[') return false;
    }
    else if(c == ']'){
      if(p.top() == '[') p.pop();
      else if(p.top() == '(') return false;
    }
    cin >> c;
  }
  return p.empty();
}

int main(){
  bool f = correct();
  if(f) cout << "Correcte" << endl;
  else cout << "Incorrecte" << endl;

}

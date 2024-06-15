#include <iostream>
#include <map>
using namespace std;


struct Info {
  string code;
  int price;
};


int main() {
  map<int, Info> M;
  char c;
  while (cin >> c) {
    if (c == 'n') {
      cout << "num: " << M.size() << endl;
    }
    else if (c == 'u') {
      string code;
      int length, price;
      cin >> code >> length >> price;
      Info I;
      I.code = code;
      I.price = price;
      M[length] = I;
    }
    else if (c == 'q') {
      int length;
      cin >> length;
      auto it = M.find(length);
      if(it == M.end()) cout << -1 << endl;
      else cout << it->second.price << endl;
    }
    else if (c == 'p') {
      cout << string(10, '-') << endl;
      for(auto it = M.begin(); it != M.end(); ++it) 
          cout << it->second.code << " " << it->first << " " << it->second.price << endl; 
      cout << string(10, '*') << endl;
    }
    else { // c == 's'
      auto it = M.begin();
      if(it == M.end() or M.size() < 2) cout << "no" << endl;
      else 
      {
        ++it;
        cout << it->second.code << " " << it->first << " " << it->second.price << endl;
      }
    }
  }
}

#include <iostream>
using namespace std;


int oper() {
    
    char op;
    
    cin >> op;
    
    if (op >= '0' and op <= '9') {
        int n = op - '0';
        return n;
        
    }
    else {
        if (op == '+') return oper() + oper();
        else if (op == '-') return oper() - oper();
        else return oper() * oper();
        
    }

                                                           
}

int main() {
    
    cout << oper() << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {


    char c;
    

    while (cin >> c) {

        int x = 0, res = 0;

        if(c == 'X') res = res + 10;
        else if(c == '?') x = 10;
        else res = res + (c-48)*10;

        for (int i = 9; i > 0; --i){
            cin >> c;
            if(c == 'X') res = res + 10;
            else if(c == '?') x = i;
            else res = res + (c-48)*i;
        }
    
        bool found = false;
        int num = 0;

        while(not found and num < 11){

            if ((res + num*x)%11 == 0) found = true;
            else ++num;
        }
        
        if (num == 10) cout << "X" << endl;
        else cout << num << endl;
    }
}
    
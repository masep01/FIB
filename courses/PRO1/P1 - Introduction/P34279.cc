#include <iostream>
using namespace std;

int main(){
    
    int h, m, s;
    
    cin >> h >> m >> s;

    if (s < 59) 
        s = s + 1;
    
    else {
        s = 0;
        
        if (m < 59) m = m + 1;
        else {
            m = 0;
            if (h <= 24 and h != 23) h = h + 1;
        
            else h = 0;
        }
    }
    
    if (h < 10) cout << "0" << h << ":" ; 
        else cout << h << ":";
            
    if (m < 10) cout << "0" << m << ":";
        else cout << m << ":";
    
    if (s < 10) cout << "0" << s << endl; 
        else cout << s << endl;
        
   
        
   
    
}

#include <iostream>
using namespace std;

int main() {
    int n,h,m,s,x;
   
    cin >> n;
    
    h = n/3600;
    x = (n%3600);
    m = (n%3600)/60;
    s = (x%60);
    
    cout <<h<< ' ' <<m<< ' ' <<s<< endl;
    
}

#include <iostream>
using namespace std;

int main(){
    
    double a;
    cin >> a;
    
    int pinf = a;
    int psup;
    double pdec = (a - pinf)*10;
    int arr;
    
    if (pdec != 0) {
        
       psup = pinf+1;
       
    } else {
        psup= a;
        arr = pinf;
    }
       
    if (pdec >= 5) {
       arr= pinf + 1;
       
    } else arr=pinf;
   
    
    cout << pinf << " " << psup << " " << arr << endl;
    
    
}

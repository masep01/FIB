#include <iostream>	
#include <cmath>
using namespace std;



void trig (double& sinus, double& cosinus) {
    
    sinus = sin(sinus);
    cosinus = cos(cosinus);
    
}


int main() {
    
    cout.setf(ios::fixed);
    cout.precision(6);
    
    double angle;
    
    while (cin >> angle) {
        angle = angle * (M_PI/180);
        double sin = angle, cos = angle;
        
        trig(sin, cos);
        
        cout << sin << " " << cos << endl;
    }
    
    
    
    
}

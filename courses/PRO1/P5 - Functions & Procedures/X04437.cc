#include <iostream>	
#include <cmath>
using namespace std;


double dist_or(double x, double y){

    return sqrt((x*x) + (y*y));
}

int main () {
    cout.setf(ios::fixed);
    cout.precision(3);
    
    double x, y;
    cin >> x >> y;

    cout << dist_or(x,y) << endl;
}
#include <iostream>
#include <cmath>

using namespace std;

struct Punt {
    
    double x, y;
    
};

double distancia(const Punt& a, const Punt& b){
    
    double d1 = a.x - b.x;
    double d2 = a.y - b.y;
    return sqrt(pow(d1,2) + pow(d2,2));
    
}

int main (){
    
   double x1, y1;
   double x2, y2;
   
   cin >> x1 >> y1;
   cin >> x2 >> y2;
   
   Punt p1;
   Punt p2;
   
   p1.x = x1;
   p1.y = y1;
   
   p2.x = x2;
   p2.y = y2;
   
   cout << distancia(p1, p2) << endl;
    
}

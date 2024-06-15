#include <iostream>
using namespace std;

int main() {
    
    int y, d, h, m, s, r;

    cin >> y >> d >> h >> m >> s;

    r= (y*31536000) + ((d*24)*3600) + (h*3600) + (m*60) + s;

    cout << r << endl;
    
}

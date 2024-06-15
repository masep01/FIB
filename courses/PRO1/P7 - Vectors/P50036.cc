#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int avalua(const vector<int>& p, int x){

    int n = p.size();
    int res = 0;

    for (int i = 0; i < n; ++i){
        res = res + (p[i]*(pow(x,i)));
    }
    return res;
}


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int posicio_maxim(const vector<double>& v, int m){
    if(m == 0) return 0;

    int pos_max = 0;
    for(int i = 0; i <= m; ++i){
        if (v[i] > v[pos_max]){
            pos_max = i;
        }
        else if (v[i] == v[pos_max]){
            if(i < pos_max) pos_max = i;
        }
    }
    return pos_max;
}
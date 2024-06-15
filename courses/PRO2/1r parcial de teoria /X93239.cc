#include <iostream>
#include <vector>
using namespace std;
 
/* Pre: cert */
/* Post: el resultat es el nombre d'elements frontissa de v */
int comptatge_frontisses(const vector<int> &v)
{
    int sum_pre = 0;
    int sum_post = 0;
    int fr = 0;
    for(int i = 0; i < v.size(); ++i) sum_post += v[i];

    for (int k = 0; k <  v.size(); ++k)
    {
        if(k>0) sum_pre += v[k-1];
        sum_post -= v[k];
        if(sum_post - sum_pre == v[k]) ++fr;
    }

    return fr;
    
}
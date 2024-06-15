#include <iostream>
#include <vector>
using namespace std;
 
 /* Pre: v.size() > 0 */
/* Post: el resultat es el nombre de solitaris a v */
int solitaris(const vector<int> &v)
{
    int sum = 0;
    int n = v.size();

    if(n > 1 and v[0] != v[1]) ++sum;
    for(int i = 1; i < n - 1; ++i){
        if((v[i-1] != v[i]) and (v[i+1] != v[i])) ++sum;
    }
    if(v[n-2] != v[n-1]) ++sum;
    return sum;
    
}

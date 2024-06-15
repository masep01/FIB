#include <vector>

using namespace std;

struct parint {int prim, seg;};

parint max_min1(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
  el segundo componente del resultado es el valor minimo de v */
{
  parint par_int;

  par_int.prim = v[0];
  par_int.seg = v[0];

  for(int i = 1; i < v.size(); ++i){
    if(v[i] < par_int.seg) par_int.seg = v[i];
    if(v[i] > par_int.prim) par_int.prim = v[i];
  }
  return par_int;
}

pair<int,int> max_min2(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
{
  pair<int,int> parell;

  parell.first = v[0];
  parell.second = v[0];

  for(int j = 1; j < v.size(); ++j){
    if(v[j] < parell.second) parell.second = v[j];
    if(v[j] > parell.first) parell.first = v[j];
  }

  return parell;

}

void max_min3(const vector<int>& v, int& x, int& y)
/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
{
  x = v[0];
  y = v[0];

  for(int k = 1; k < v.size(); ++k){
    if(v[k] < y) y = v[k];
    if(v[k] > x) x = v[k];
  }

}

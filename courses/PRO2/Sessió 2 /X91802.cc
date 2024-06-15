#include "Estudiant.hh"
#include <vector>
#include <iostream>
using namespace std;

pair<int,int>  max_min_vest(const vector<Estudiant>& v)
/* Pre: v no conte repeticions de dni  */
/* Post: si existeix a v algun estudiant amb nota, la primera component del
   resultat es la posicio de l'estudiant de nota maxima de v i la segona
   component es la posicio de l'estudiant de nota minima de v (si hi ha
   empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
   hi ha cap estudiant amb nota, totes dues components valen -1 */
{
  int index = 0;

  while(index < v.size() and not v[index].te_nota()) ++index;

  int min = index;
  int max = index;

  for (int i = index; i < v.size(); i++) {
    if(v[i].te_nota()){

      if(v[i].consultar_nota() < v[min].consultar_nota()) min = i;
      else if (v[i].consultar_nota() == v[min].consultar_nota() and v[i].consultar_DNI() < v[min].consultar_DNI()) min = i;
      else if(v[i].consultar_nota() > v[max].consultar_nota()) max = i;
      else if (v[i].consultar_nota() == v[max].consultar_nota() and v[i].consultar_DNI() < v[max].consultar_DNI()) max = i;
    }
  }
    pair<int,int> parell;

    if(index == v.size()){
      parell.first = -1;
      parell.second = -1;
    }
    else {
      parell.first = max;
      parell.second = min;
    }
    return parell;
}

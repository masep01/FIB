#include <iostream>
#include <list>
using namespace std;
 
/* Pre: l no es buida, sol es buida */
/* Post: sel es el resultat de treure d'l els elements febles en mitjana */
void seleccio(const list<double>& l, list<double>& sel)
{
   
    double n = 1;
    list<double>::const_iterator it = l.begin();
    list<double>::iterator it_sel = sel.begin();
    double sum = *it;
    sel.insert(it_sel,*it);
    ++it;
    while(it != l.end()){
        if(*it >= sum/n) sel.insert(it_sel,*it);
        sum += *it;
        ++n;
        ++it;
    }
}

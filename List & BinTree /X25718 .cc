#include "LlistaIOEstudiant.hh"


/* Pre: x>=0, t = T */
/* Post: t es com a T pero sense cap estudiant amb dni = x */
void esborra_tots(list<Estudiant> &t, int x){

  list<Estudiant>::iterator it = t.begin();
  while(it != t.end()){
    if((*it).consultar_DNI() == x) it = t.erase(it);
    else ++it;
  }
}

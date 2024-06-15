#include "LlistaIOEstudiant.hh"
using namespace std;

void b(const list<Estudiant>& l, int dni){
  int ap = 0;
  list<Estudiant>::const_iterator it;

  for(it = l.begin(); it != l.end(); ++it){
    if((*it).consultar_DNI() == dni) ++ap;
  }
  cout << dni << " " << ap << endl;
}

int main(){

  list<Estudiant> l;
  LlegirLlistaEstudiant(l);
  int dni;
  cin >> dni;

  b(l,dni);

}

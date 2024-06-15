#include "LlistaIOParInt.hh"
using namespace std;

void b(const list<ParInt>& l, int n){
  int suma = 0;
  int ap = 0;
  list<ParInt>::const_iterator it;

  for(it = l.begin(); it != l.end(); ++it){
    if((*it).primer() == n) {
      ++ap;
      suma += (*it).segon();
    }
  }

  cout << n << " " << ap << " " << suma << endl;
}

int main(){

  list<ParInt> l;
  LlegirLlistaParInt(l);
  int n;
  cin >> n;

  b(l,n);

}

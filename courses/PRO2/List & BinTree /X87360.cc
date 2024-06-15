#include <iostream>
#include <list>
// #include "listIOint.hh"
using namespace std;

/* Pre: uno = U */
/* Post: uno pasa a ser la interseccion de U y dos */
void inter(list<int>& uno, const list<int>& dos )
{
    list<int>::const_iterator it2 = dos.begin();
    list<int>::iterator it1 = uno.begin();

    while(not uno.empty() and it1 != uno.end() and it2 != dos.end()){
        
        if( (*it1) == (*it2) ) {
            ++it1; 
            ++it2;
        }
        else if( (*it1) > (*it2) ){
           while(it2 != dos.end() and (*it1) > (*it2)) ++it2;
           
        }
        else it1 = uno.erase(it1);
    }
    if(it2 == dos.end()){
        while(not uno.empty() and it1 != uno.end()) it1 = uno.erase(it1);
    }
    
}
 
// int main()
// {
//     list<int> uno, dos;
//     llegir_llista_int(uno, 0);
//     llegir_llista_int(dos, 0);
//     inter(uno,dos);
//     escriure_llista_int(uno);
// }


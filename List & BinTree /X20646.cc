#include <iostream>
#include "BinTreeIOParInt.hh"
#include "ParInt.hh"
using namespace std;

void dfs(const BinTree<ParInt>& a, int n, int deep, bool& f){
    if(not a.empty()){
        if(a.value().primer() == n) {
            cout << a.value().primer() << " " << a.value().segon() << " " << deep << endl; 
            f = true;
        }
        else {
            if (not a.left().empty()) dfs(a.left(), n, deep + 1, f);
            if (not a.right().empty()) dfs(a.right(), n, deep + 1, f);
        }
    }
}

int main(){

    BinTree<ParInt> arbre;
    read_bintree_parint(arbre);
    
    int n;
    bool f;
    while(cin >> n) {
        f = false;
        dfs(arbre, n, 0,f );
        if(not f) cout << -1 << endl;
    }
}
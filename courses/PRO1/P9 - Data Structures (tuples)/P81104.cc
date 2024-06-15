#include <iostream>
#include <vector>
using namespace std;

struct Assignatura {
    string nom;                 // Nom de l’assignatura
    double nota;                // Entre 0 i 10, -1 indica NP
};

struct Alumne {
    string nom;                 // Nom de l’alumne
    int dni;                    // DNI de l’alumne
    vector<Assignatura> ass;    // Llista d’assignatures de l’alumne
};

double nota(const vector<Alumne>& alums, int dni, string nom){

    bool found = false;
    int index = 0;

    while (not found and index < alums.size()){
        if(alums[index].dni == dni) found = true;
        else ++index;
    }
    if(not found) return -1;
    int index2 = 0;
    found = false;

    while( not found and index2 < alums[index].ass.size()){  
        if(alums[index].ass[index2].nom == nom) return alums[index].ass[index2].nota;
        else ++index2;
    }   
    return -1;
}

double mitjana(const vector<Assignatura>& ass){

    if (ass.size() == 0) return -1;
    else {
        double mitjana = 0;
        int cont = 0;
        bool te_nota = false;

        for(int i = 0; i < ass.size(); ++i){
            if(ass[i].nota != -1){
                 mitjana += ass[i].nota;
                 ++cont;
                 te_nota = true;
            }
        }
        if(not te_nota) return -1;
        else return mitjana/cont;
    }
   
}

void compta(const vector<Alumne>& alums, int dni, string nom, int& com){

        double note = nota(alums,dni,nom);

        for (int i = 0; i < alums.size(); i++){
            if (note < mitjana(alums[i].ass)) ++com;
        }
    
}

int main(){

    int n, m;
    cin >> n;
    vector<Alumne> alums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> alums[i].nom >> alums[i].dni;
        cin >> m;
        vector<Assignatura> subjects(m);
        for (int j = 0; j < m; j++) {
            cin >> subjects[j].nom >> subjects[j].nota;
        }
        alums[i].ass = subjects;
    }
    
    int dni;
    string assi;

    while (cin >> dni >> assi){
        int com = 0;
        compta(alums,dni,assi,com);
        cout << com << endl;
    }
    

}

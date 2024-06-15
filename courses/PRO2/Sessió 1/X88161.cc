#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<pair<int, int>> Partit; 
typedef vector<Partit> Lliga;  

struct equip {
    int num, punts = 0, gols = 0, rebuts = 0;
};

Lliga llegir_taula(int n){
    Lliga lliga(n, Partit(n));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> lliga[i][j].first;
            cin >> lliga[i][j].second;
        }
    }
    return lliga;
}

int resultat(int a, int b){  // Torna 1 si guanya a, 2 si guanya b o 0 en cas d'empat
    if (a > b) return 1;
    else if(a < b) return 2;
    else return 0;
}

void recompte(const Lliga& lliga, vector<equip>& vec){
    int size = lliga.size();
    
    int gols_i;
    int gols_j;

    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            if(i - j != 0){
                gols_i = lliga[i][j].first;
                gols_j = lliga[i][j].second;

                int res = resultat(gols_i, gols_j);

                if(res == 1) vec[i].punts += 3;
                else if(res == 2) vec[j].punts += 3;
                else{
                    vec[i].punts ++;
                    vec[j].punts ++;
                }

                vec[i].gols += gols_i;
                vec[j].gols += gols_j;

                vec[i].rebuts += gols_j;
                vec[j].rebuts += gols_i;
            }  
        }
    }
}

bool cond(const equip& a, const equip& b){
    if(a.punts != b.punts) return a.punts > b.punts;
    if(a.gols - a.rebuts != b.gols - b.rebuts) return a.gols - a.rebuts > b.gols - b.rebuts;
    return a.num < b.num;
}

void print(vector<equip>& vec){
    for(int i = 0; i < vec.size(); ++i){
        cout << vec[i].num  << " "
             << vec[i].punts << " " 
             << vec[i].gols << " " 
             << vec[i].rebuts << endl;
    }
}

int main() {

    int n;
    cin >> n;
    Lliga lliga = llegir_taula(n);

    vector<equip> vec(n);
    for(int k = 1; k <= n; ++k) vec[k-1].num = k; //Assignacio dels numeros als equips: 1,2,3 ...

    recompte(lliga, vec);
    sort(vec.begin(), vec.end(), cond);
    print(vec);


}
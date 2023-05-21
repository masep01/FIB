#include <iostream>
#include <queue>
using namespace std;

int calc_max(queue<int> c){
    int max = c.front();
    while(not c.empty()){
        if(c.front() > max) max = c.front();
        c.pop();
    }
    return max;
}

int calc_min(queue<int> c){
    int min = c.front();
    while(not c.empty()){
        if(c.front() < min) min = c.front();
        c.pop();
    }
    return min;
}

void print_stats(int max, int min, double mitjana){
    cout << "min " << min;
    cout << "; max " << max;
    cout << "; media " << mitjana << endl;
}

int main(){

    queue<int> cua;

    int n;
    double suma = 0;
    int max = -1002, min = 1001;
    cin >> n;
    while(n > -1002 and n < 1001){

        if(n == -1001){
            if(not cua.empty()){
                 int aux = cua.front();
                 cua.pop();
                 suma -= aux;
                 if((aux == min or aux == max)  and not cua.empty()){
                     max = calc_max(cua);
                     min = calc_min(cua);
                 }
            }
        } 
        else {
            cua.push(n);
            if(cua.size() == 1){
                suma = n;
                min = max = n;
            }
            else suma += n;
            if(n < min) min = n;
            if(n > max) max = n;
        }
        if(cua.empty()) cout << 0 << endl;
        else print_stats(max, min, suma/cua.size());

        cin >> n;
    }
}
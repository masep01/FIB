#include <iostream>	

using namespace std;



void infoSequencia(int& max, int& lpos) {

    int n;
    bool found = false;
    cin >> n;

    while (not found and n!=0) {
        if (n == max) found = true;
        else ++lpos;
        cin >> n;
    }
    if (not found) lpos = 0;
}


int main() {
 
    int n, cont = 1, cont_max = 1, lpos = 1;
    cin >> n;
    int max = n;
    
    while (n != 0) {

        if (n >= max){ 
            max = n;
            cont_max = cont;
        }
        
        cin >> n;
        ++cont;
    }
    infoSequencia(max,lpos);
    if (lpos == 0) cout << max << " " << cont_max << " " << "-" << endl;
    else cout << max << " " << cont_max << " "  << lpos << endl;

}

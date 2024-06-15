#include <iostream>
#include <vector>

using namespace std;

typedef vector <vector<int> > Matriu;

int main (){
    
    int files, columnes;
    cin >> files >> columnes;
    
    Matriu matriu(files,vector<int>(columnes));
   
    for (int i = 0; i < files; ++i){
        for (int j = 0; j < columnes; ++j) cin >> matriu[i][j];
    }
    
    string word;
    int num;
    
    while(cin >> word){
        
        if(word == "fila"){
            cin >> num;
            cout << word << " " << num << ":";
            for (int k = 0; k < columnes; ++k) cout << " " << matriu[num-1][k];
            cout << endl;
        }
        else if(word == "columna"){
            cin >> num;
            cout << word << " " << num << ":";
            for (int l = 0; l < files; ++l) cout << " " << matriu[l][num-1];
            cout << endl;
        }
        else{
            int num2;
            cin >> num >> num2;
            cout << word << " " << num << " " << num2 << ":";
            cout << " " << matriu[num - 1][num2 - 1];
            cout << endl;
            
        }
        
    }  
    
}

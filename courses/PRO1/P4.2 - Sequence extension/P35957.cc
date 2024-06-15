#include <iostream>	
using namespace std;

int main () {

    int n;
	cin >> n;
    n = 2*n;
    int a, b;
	bool finished = false;
    char winner = '=';

    cin >> a >> b;

    if (a > 9 and a < 100) winner = 'B';
    else {
        for (int i = 0; i < n and not finished; ++i) {

        if (a == b) {
            a = b;
            cin >> b;
        }
        else {

            int digits_a = 1, digits_b = 1;
            int aux_a = a, aux_b = b;

            while (aux_a > 9) {     //busquem el numero de digits de A
                aux_a = aux_a/10;
                ++digits_a;
            }
            
            while (aux_b > 9) {     //busquem el numero de digits de B
                aux_b = aux_b/10;
                ++digits_b;
            }

            if (digits_a%2 == 0 or digits_b%2 == 0) {   // si el nº de digits es parell mirem qui guanya
             
                if (i%2 == 0){  

                    if (digits_a%2 == 0){    
                        finished = true;
                        winner = 'B';
                    } 
                    else if (digits_b%2 == 0){    
                        finished = true;
                        winner = 'A';
                    }

                } 
                else {

                    if (digits_a%2 == 0){    
                        finished = true;
                        winner = 'A';
                    } 
                    else if (digits_b%2 == 0){    
                        finished = true;
                        winner = 'B';
                    }
                }
            } 
            else {                           //sino mirem el digit central

                int digitcentral_a = digits_a/2;
                int digitcentral_b = digits_b/2;
                int aux2_a = a;
                int aux2_b = b;

                for (int j = 0; j < digitcentral_a; ++j) {  // busquem el digit central de A
                    aux2_a = aux2_a/10;
                }
                digitcentral_a = aux2_a%10;  

                for (int k = 0; k < digitcentral_b; ++k) {      //busquem el digit central de B
                    aux2_b = aux2_b/10;
                }
                digitcentral_b = aux2_b%10; 

                if (digitcentral_a != digitcentral_b) {  //si no son iguals, veiem qui guanya

                    if (i%2 == 0){

                        if (digitcentral_a != digitcentral_b) {  //els comparem
                            winner = 'A';
                            finished = true;
                        }
                        else winner = 'B';
                    }
                    else {

                        if (digitcentral_a != digitcentral_b) {  //els comparem
                            winner = 'B';
                            finished = true;
                        }
                        else winner = 'A';
                    }
                }
                else {  //si son iguals, passem de ronda

                    a = b;                 
                    cin >> b;

                }
            }
        }

    }
    }
    cout << winner << endl;
    
}
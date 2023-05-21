#include <iostream>	
#include <cmath>
using namespace std;


int nombre_digits(int n) {
    
    if (n < 10) return 1;
    else return nombre_digits(n/10) + 1;

}

int main () {
    

}
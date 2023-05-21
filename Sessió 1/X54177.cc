#include <iostream>
using namespace std;

int main()
{
  int num;
  cin >> num;
  int marca;
  cin >> marca;
  int x;
  string s;

  for (int i = 1; i <= num; i++) {
    int suma = 0;
    cin >> x;
    while(x != marca){
      suma += x;
      cin >> x;
    }
    cout << "La suma de la secuencia " << i << " es " << suma << endl;
    getline(cin, s);
  }
}


// prueba
// otra prueba

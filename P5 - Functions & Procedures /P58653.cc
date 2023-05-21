
#include <iostream>	
#include <cmath>
using namespace std;

void escriu_linia(char c, string s, bool b) {

    cout << s << "('" << c << "') = ";

    if (b) cout << "cert" << endl;

    else cout << "fals" << endl;
}
    
void tipus(char c) {

    string s;
    bool b = false;

    s = "lletra";

    if ((c >= 65 and c <= 90) or (c >= 97 and c <= 122)) b = true;
    else b = false;
    escriu_linia(c,s,b);
    
    s = "vocal";

    if (c == 65 or c == 97 or c == 69 or c == 101 or c == 73 or c == 105 or c == 79 or c == 111 or c == 85 or c == 117) b = true;
    else b = false;
    escriu_linia(c,s,b);

    s = "consonant";

    if (c != 65 and c != 97 and c != 69 and c != 101 and c != 73 and c != 105 and c != 79 and c != 111 and c != 85 and c != 117 and ((c >= 65 and c <= 90) or (c >= 97 and c <= 122))) b = true;
    else b = false;
    escriu_linia(c,s,b);

    s = "majuscula";

    if (c >= 65 and c <= 90) b = true;
    else b = false;
    escriu_linia(c,s,b);

    s = "minuscula";

    if (c >= 97 and c <= 122) b = true;
    else b = false;
    escriu_linia(c,s,b);

    s = "digit";

    if (c >= 48 and c <= 57) b = true;
    else b = false;
    escriu_linia(c,s,b);

}


int main () {
    char c;
    cin >> c;

    tipus(c);
    
}

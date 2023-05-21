#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double> &v, int esq, int dre)
{
    if(esq > dre) return -1;
    int m = (esq+dre)/2;
    if(x > v[m]) return posicio(x,v, m+1, dre);
    if(x < v[m]) return posicio(x, v, esq, m-1);
    return m;
}

// int first_occurrence(double x, const vector<double>& v)
// {

// }

int main()
{

}
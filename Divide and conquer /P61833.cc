#include <iostream>
#include <vector>
using namespace std;


typedef vector<vector<int>> Matrix;

Matrix mult(const Matrix &M1, const Matrix &M2, int m)
{
    Matrix R = {{0, 0},{0, 0}};
    R[0][0] = (M1[0][0]*M2[0][0]%m + M1[0][1]*M2[1][0]%m)%m;
    R[0][1] = (M1[0][0]*M2[0][1]%m + M1[0][1]*M2[1][1]%m)%m;
    R[1][0] = (M1[1][0]*M2[0][0]%m + M1[1][1]*M2[1][0]%m)%m;
    R[1][1] = (M1[1][0]*M2[0][1]%m + M1[1][1]*M2[1][1]%m)%m;
    return R;
}

Matrix power(const Matrix &M, int n, int m)
{
    if(n == 0) return {{1, 0},{0, 1}};
    Matrix R = power(M, n/2, m);
    R = mult(R, R, m);
    if(n%2 ==1) R = mult(R, M , m);
    return R;
}

int main()
{
    int a00, a01, a10, a11;
    int n, m;
    while(cin >> a00 >> a01 >> a10 >> a11)
    {
        cin >> n >> m;
        Matrix M = {{a00%m, a01%m},{a10%m, a11%m}};
        Matrix N = power(M, n, m);
        cout << N[0][0] << " " << N[0][1] << endl;
        cout << N[1][0] << " " << N[1][1] << endl;
        cout << "----------" << endl;
    }
   
}
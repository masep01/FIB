#include <iostream>
#include <queue>
#include "ParInt.hh"
#include "CuaIOParInt.hh"
using namespace std;

queue<ParInt> separate(queue<ParInt>& c, queue<ParInt>& c1){
    queue<ParInt> c2;
    int sum1 = 0;
    int sum2 = 0;

    while(not c.empty()){ 
        if(not c1.empty() and sum1 > sum2){
            c2.push(c.front());
            sum2 += c.front().segon();
            c.pop();
        }
        else{
            c1.push(c.front());
            sum1 += c.front().segon();
            c.pop();
        }
    }
    return c2;

}

int main(){
    queue<ParInt> c;

    llegirCuaParInt(c);

    queue<ParInt> c1;
    queue<ParInt> c2 = separate(c,c1);

    escriureCuaParInt(c1);
    cout << endl;
    escriureCuaParInt(c2);
}

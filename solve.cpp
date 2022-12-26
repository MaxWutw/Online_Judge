#include <iostream>
using namespace std;
int main(){
    long long int f[100];
    f[0] = 1;
    f[1] = 1;
    for(int i = 2;i < 80;i++)
        f[i] = f[i-1]+f[i-2];
    cout << f[69] << endl;//ouput = 190392490709135

    return 0;
}
// Fast Fibonacci Modulo Algorithm

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
struct Matrix{
    ll arr[2][2] = {{0}};
    Matrix operator *(Matrix a){
        Matrix tmp;
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < 2;j++){
                for(int k = 0;k < 2;k++){
                    tmp.arr[i][j] = ((tmp.arr[i][j] + (arr[i][k] * a.arr[k][j]) % mod) % mod) % mod;
                }
            }
        }
        return tmp;
    }
};
Matrix fast_pow(Matrix base, ll p){
    Matrix res;
    res.arr[0][0] = 1, res.arr[0][1] = 0, res.arr[1][0] = 0, res.arr[1][1] = 1;
    while(p){
        if(p & 1) res = base * res;
        base = base * base;
        p >>= 1;
    }
    return res;
}
int main(){
    IOS
    ll n;
    Matrix base;
    base.arr[0][0] = 1;
    base.arr[0][1] = 1;
    base.arr[1][0] = 1;
    base.arr[1][1] = 0;
    cin >> n;
    if(n == 0){
        cout << 0 << '\n';
        return 0;
    }
    Matrix output = fast_pow(base, n - 1);
    cout << output.arr[0][0] << '\n';

    return 0;
}

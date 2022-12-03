#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
struct Matrix{
    ll mat[2][2] = {0};
    Matrix operator * (Matrix &inp){
        Matrix tmp;
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < 2;j++){
                for(int k = 0;k < 2;k++){
                    tmp.mat[i][j] = ((tmp.mat[i][j] + (mat[i][k] % mod) * (inp.mat[k][j] % mod)) % mod) % mod;
                }
            }
        }
        return tmp;
    }
};
Matrix matrix_pow(ll exp){
    Matrix res, base;

    res.mat[0][0] = 1;
    res.mat[0][1] = 0;
    res.mat[1][0] = 1;
    res.mat[1][1] = 0; // Identity matrix

    base.mat[0][0] = 1;
    base.mat[0][1] = 1;
    base.mat[1][0] = 1;
    base.mat[1][1] = 0; // base matrix
    while(exp){
        if(exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}
ll num_pow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int main(){
    IOS
    int n;
    cin >> n;
    while(n--){
        ll exp_a, exp_b;
        cin >> exp_a >> exp_b;
        Matrix a = matrix_pow(exp_a - 1), b = matrix_pow(exp_b - 1);
        // cout << a.mat[0][0] << ' ' << b.mat[0][0];
        cout << num_pow(a.mat[0][0], b.mat[0][0]) << '\n';
    }

    return 0;
}
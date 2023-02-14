// Fermat’s Little Theorem and fast exponential and modular modular inverse
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll n, p;
int fast_exp(ll a, ll exp){
    ll res = 1;
    while(exp > 0){
        if(exp & 1) res = res * a % p;
        a = a * a % p;
        exp >>= 1;
    }
    return res % p;
}
int main(){
    IOS
    cin >> n >> p;
    while(n--){
        int a;
        cin >> a;
        cout << fast_exp(a, p - 2) << ' ';
    }

    return 0;
}
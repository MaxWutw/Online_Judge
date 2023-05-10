// dp
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll dp[1000005];
int main(){
    IOS
    ll n;
    cin >> n;
    dp[0] = 1;
    for(ll i = 1;i <= n;i++){
        for(ll j = 1;j <= min(i, 6LL);j++){
            dp[i] += dp[i - j];
            dp[i] %= mod;
        }
    }
    cout << dp[n] << '\n';

    return 0;
}
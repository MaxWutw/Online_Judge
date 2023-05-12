#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll v[105], w[105], dp[100005];
int main(){
    IOS
    ll n, weight;
    fill(dp, dp + 100005, (ll)1e18);
    cin >> n >> weight;
    dp[0] = 0;
    for(int i = 0;i < n;i++) cin >> w[i] >> v[i];
    for(int i = 0;i < n;i++){
        for(int j = 100000;j >= 1;j--){
            if(j - v[i] >= 0)
                dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    ll ans = 0;
    for(ll i = 1;i <= 100000;i++){
        if(dp[i] <= weight)
            ans = max(ans, i);
    }
    cout << ans << '\n';

    return 0;
}
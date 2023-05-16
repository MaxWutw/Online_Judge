// dp
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const ll INF = 1e18;
ll d[505], a[505];
ll dp[505][505];
int main(){
    IOS
    int n, l, k;
    cin >> n >> l >> k;
    for(int i = 0;i < n;i++) cin >> d[i];
    for(int i = 0;i < n;i++) cin >> a[i];
    d[n] = l;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= k;j++){
            dp[i][j] = INF;
        }
    }
    for(int i = 0;i <= k;i++) dp[0][i] = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= k;j++){
            for(int p = i - 1;p >= 0;p--){
                if(j - (i - p - 1) < 0) break;
                dp[i][j] = min(dp[i][j], dp[p][j - (i - p - 1)] + (a[p] * (d[i] - d[p])));
            }
        }
    }
    ll ans = dp[n][0];
    for(int i = 0;i <= k;i++) ans = min(ans, dp[n][i]);
    cout << ans << '\n';

    return 0;
}
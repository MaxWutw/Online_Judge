#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll n, x, w[22];
pair<ll, ll> dp[1 << 22];
int main(){
    IOS
    cin >> n >> x;
    for(int i = 0;i < n;i++) cin >> w[i];
    for(int i = 0;i < n;i++) dp[i] = {n + 1, 0};
    dp[0].first = 1, dp[0].second = 0;
    for(int mask = 0;mask < (1 << n);mask++){
        for(int i = 0;i < n;i++){
            if(mask & (1 << i)){
                pair<ll, ll> tmp = dp[(mask ^ (1 << i))];
                if(tmp.second + w[i] > x){
                    tmp = {tmp.first + 1, w[i]};
                }
                else{
                    tmp.second += w[i];
                }
                dp[mask] = min(dp[mask], tmp);
            }
        }
    }
    for(int i = 0;i < 10;i++) cout << dp[i].first << ' ';
    // cout << dp[(1 << n) - 1].first << '\n';

    return 0;
}

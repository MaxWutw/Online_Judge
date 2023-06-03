// 0/1 Knapsack
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll c[1005], p[1005];
int main(){
    IOS
    ll n, x;
    cin >> n >> x;
    for(int i = 0;i < n;i++) cin >> c[i];
    for(int i = 0;i < n;i++) cin >> p[i];
    ll dp[100005];
    for(int i = 0;i <= x;i++){
        dp[i] = 0;
    }
    for(int i = 0;i < n;i++){
        for(int j = x;j >= 0;j--){
            if(j - c[i] >= 0)
                dp[j] = max(dp[j], dp[j - c[i]] + p[i]);
        }
    }
    cout << dp[x] << '\n';

    return 0;
}

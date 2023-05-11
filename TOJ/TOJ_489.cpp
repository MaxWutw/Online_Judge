// dp
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll arr[200005], pre[200005], dp[200005], ans = 0;
int main(){
    IOS
    int n, k;
    cin >> n >> k;
    memset(dp, 0, sizeof(dp));
    pre[0] = 0;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }
    dp[k] = pre[k];
    for(int i = k + 1;i <= n;i++){
        dp[i] = max(dp[i - 1], dp[i - k - 1] + pre[i] - pre[i - k]);
    }
    cout << dp[n] << '\n';

    return 0;
}
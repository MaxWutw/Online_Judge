// range dp, unrealized
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll arr[3005], dp[3005][3005], pre[3005];
int main(){
    IOS
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        dp[i][i] = arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }
    for(int d = 1;d <= n;d++){
        for(int l = 1;l + d <= n;l++){
            int r = l + d;
            dp[l][r] = max(arr[l] + pre[r] - pre[l] - dp[l + 1][r], arr[r] + pre[r - 1] - pre[l - 1] - dp[l][r - 1]);
        }
    }
    cout << dp[1][n] - (pre[n] - dp[1][n]) << '\n';

    return 0;
}

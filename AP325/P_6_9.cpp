// 01 knapsack problem
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int w[105], v[105], dp[105][100005];
int main(){
    IOS
    int n, W;
    cin >> n >> W;
    for(int i = 1;i <= n;i++) cin >> w[i];
    for(int i = 1;i <= n;i++) cin >> v[i];
    memset(dp, 0, sizeof(dp));
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= W;j++){
            if(j < w[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    cout << dp[n][W] << '\n';

    return 0;
}

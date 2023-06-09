// range dp
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll dp[405][405];
ll arr[405], pre[405];
int main(){
    IOS
    int n;
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        dp[i][i] = 0;
    }
    pre[0] = 0;
    for(int i = 1;i <= n;i++) pre[i] = pre[i - 1] + arr[i];
    for(int l = n;l >= 1;l--){
        for(int r = l;r <= n;r++){
            for(int k = l;k < r;k++){
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + pre[r] - pre[l - 1]);
            }
        }
    }
    cout << dp[1][n] << '\n';

    return 0;
}

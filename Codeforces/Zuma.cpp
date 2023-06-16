#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int dp[505][505], arr[505];
int main(){
    IOS
    int n;
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        dp[i][i] = 1;
    }
    for(int l = n;l >= 1;l--){
        for(int r = l;r <= n;r++){
            if(arr[l] == arr[r] && l != r) dp[l][r] = ((r - l) == 1 ? 1 : dp[l + 1][r - 1]);
            for(int k = l;k < r;k++){
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
            }
        }
    }
    cout << dp[1][n] << '\n';

    return 0;
}

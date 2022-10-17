#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int dp[105][5], arr[105];
int main(){
    IOS
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1;i <= n;i++){
        dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
        if(arr[i] == 2 || arr[i] == 3) dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        if(arr[i] == 1 || arr[i] == 3) dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << '\n';

    return 0;
}

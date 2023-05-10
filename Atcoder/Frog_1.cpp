// dp
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n, arr[100005];
    int dp[100005];
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    dp[0] = 0, dp[1] = abs(arr[1] - arr[0]);
    for(int i = 2;i < n;i++){
        dp[i] = min(dp[i - 1] + abs(arr[i] - arr[i - 1]), dp[i - 2] + abs(arr[i] - arr[i - 2]));
    }
    cout << dp[n - 1] << '\n';

    return 0;
}
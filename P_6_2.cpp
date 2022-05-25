// dp
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n, arr[100005];
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    int dp[100005];
    dp[0] = arr[0];
    dp[1] = max(dp[0], arr[1]);
    for(int i = 2;i < n;i++){
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
    }
    cout << dp[n - 1] << '\n';

    return 0;
}

// dp
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n, a[100005], b[100005], c[100005];
    int dp[5][100005];
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i] >> b[i] >> c[i];
    dp[0][0] = a[0];
    dp[1][0] = b[0];
    dp[2][0] = c[0];
    for(int i = 1;i < n;i++){
        dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + a[i];
        dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + b[i];
        dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + c[i];
    }
    cout << max({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]}) << '\n';

    return 0;
}
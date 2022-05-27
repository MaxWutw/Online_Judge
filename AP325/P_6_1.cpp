// dp
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n;
    cin >> n;
    int arr[100005];
    for(int i = 1;i <= n;i++) cin >> arr[i];
    int dp[100005];
    dp[0] = 0;
    dp[1] = arr[1];
    for(int i = 2;i <= n;i++)
        dp[i] = min(dp[i - 1], dp[i - 2]) + arr[i];

    cout << dp[n] << '\n';

    return 0;
}

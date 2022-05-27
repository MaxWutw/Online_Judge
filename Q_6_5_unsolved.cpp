// dp
// NA 94 unsolved

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll dp[205][205];
int main(){
    IOS
    // memset(dp, 0, sizeof(dp));
    ll n, m, maximum = 0;
    cin >> n >> m;
    // if(n == 0 || m == 0){
    //     cout << 0 << '\n';
    //     return 0;
    // }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> dp[i][j];
            dp[i][j] += dp[i - 1][j];
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 1;j <= n;j++){
            int sum = 0;
            for(int k = 1;k <= m;k++){
                sum += (dp[j][k] - dp[i][k]);
                sum = (sum > 0 ? sum : 0);
                maximum = (sum > maximum ? sum : maximum);
            }
        }
    }
    cout << maximum << '\n';

    return 0;
}
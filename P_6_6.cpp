// dp
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll dp[205][205] = {0};
int main(){
    IOS
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> dp[i][j];
        }
    }
    for(int j = 1;j < m;j++)
        dp[0][j] += dp[0][j - 1];
    for(int i = 1;i < n;i++)
        dp[i][0] += dp[i - 1][0];

    for(int i = 1;i < n;i++){
        for(int j = 1;j < m;j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + dp[i][j];
        }
    }
    cout << dp[n - 1][m - 1] << '\n';
    

    return 0;
}
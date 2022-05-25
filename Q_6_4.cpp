// dp
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int dp[100005][5];
int cost[100005][5];
int main(){
    IOS
    int n, t;
    cin >> n >> t;
    
    for(int i = 0;i < n;i++)
        cin >> cost[i][0] >> cost[i][1];
    dp[0][0] = abs(cost[0][0] - t);
    dp[0][1] = abs(cost[0][1] - t);
    for(int i = 1;i < n;i++){
        dp[i][0] =  min(dp[i - 1][0] + abs(cost[i][0] - cost[i - 1][0]), dp[i - 1][1] + abs(cost[i][0] - cost[i - 1][1]));
        dp[i][1] =  min(dp[i - 1][0] + abs(cost[i][1] - cost[i - 1][0]), dp[i - 1][1] + abs(cost[i][1] - cost[i - 1][1]));
    }
    cout << min(dp[n - 1][0], dp[n - 1][1]) << '\n';

    return 0;
}

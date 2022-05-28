#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n, k;
    cin >> n >> k;
    int arr[205][5], dp[205][5];
    for(int i = 0;i < n;i++) cin >> arr[i][0] >> arr[i][1];
    int tmp;
    cin >> tmp >> tmp;
    dp[0][0] = arr[0][0] + arr[0][1];
    dp[0][1] = arr[0][0];
    dp[0][1] = arr[0][1];
    for(int i = 1;i < n;i++){
        dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) + arr[i][0] + arr[i][1];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i][0];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
    }
    for(int i = 0;i < n;i++){
        
    }

    return 0;
}
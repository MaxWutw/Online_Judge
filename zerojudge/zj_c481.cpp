// 區間 dp
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    int t;
    cin >> t;
    while(t--){
        int n, m, arr[205], dp[205][205];
        cin >> n >> m;
        for(int i = 0;i < 205;i++){
            for(int j = 0;j < 205;j++){
                dp[i][j] = INF;
            }
        }
        for(int i = 0;i < n;i++) cin >> arr[i], dp[i][i] = 1;
        for(int l = 1;l < n;l++){
            for(int i = 0, j = i + l;j < n;i++, j++){
                if(arr[i] == arr[j] || arr[j -1] == arr[j]) dp[i][j] = dp[i][j - 1];
                for(int k = i;k < j;k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        cout << dp[0][n - 1] << '\n';
    }

    return 0;
}
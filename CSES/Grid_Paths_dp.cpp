// dp
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
char arr[1005][1005];
int main(){
    IOS
    int n;
    int dp[1005][1005];
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for(int i = 1;i <= n;i++){
        string str;
        cin >> str;
        for(int j = 1;j <= n;j++){
            arr[i][j] = str[j - 1];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i == 1 && j == 1){
                if(arr[i][j] == '*') dp[i][j] = 0;
                else dp[i][j] = 1;
                continue;
            }
            if(arr[i][j] == '*') continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][n] << '\n';

    return 0;
}
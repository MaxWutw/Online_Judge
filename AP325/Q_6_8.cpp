// dp
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
string s1, s2;
int dp[505][505];
int main(){
    IOS
    cin >> s1 >> s2;
    memset(dp, 0, sizeof(dp));
    int l1 = s1.size(), l2 = s2.size(), max_ = 0;
    for(int i = 1;i <= l1;i++){
        for(int j = 1;j <= l2;j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 8;
                max_ = max_ > dp[i][j] ? max_ : dp[i][j];
            }
            else{
                dp[i][j] = max(dp[i - 1][j - 1] - 5, max(dp[i][j - 1] - 3, dp[i - 1][j] - 3));
                max_ = max_ > dp[i][j] ? max_ : dp[i][j];
                if(dp[i][j] < 0) dp[i][j] = 0;
            }
        }
    }
    cout << max_ << '\n';


    return 0;
}
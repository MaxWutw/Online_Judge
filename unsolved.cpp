#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n;
    while(cin >> n){
        int dp[30][30];
        memset(dp, 0, sizeof(dp));
        while(n--){
            char a, b;
            int t;
            cin >> a >> b >> t;
            dp[(int)a - 65][(int)b - 65] = t;
            dp[(int)b - 65][(int)a - 65] = t;
        }
        char s, e;
        cin >> s >> e;
        for(int k = 0;k < 26;k++){
            for(int i = 0;i < 26;i++){
                for(int j = 0;j < 26;j++){
                    dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
                }
            }
        }
        
        cout << dp[(int)s - 65][(int)e - 65] << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n, m, arr[205][205], dp[205][205];
    cin >> m >> n;
    memset(dp, 0, sizeof(dp));
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            cin >> arr[i][j];
            dp[i][j] = dp[i][j - 1] + arr[i][j];
        }
    }
    int max_mat = -INF;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            int sum = 0;
            for(int k = 1;k <= m;k++){
                sum += dp[k][j] - dp[k][i - 1];
                if(sum < 0) sum = 0;
                max_mat = max(max_mat, sum);
            }
        }
    }
    cout << max_mat << '\n';

    return 0;
}
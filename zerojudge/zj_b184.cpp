// 0-1 knapsack problem
// 2 dim version
// AC (0.3s, 381.8MB)
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int v[10000], k[10000];
int dp[10000][10000];
int main(){
    IOS
    int n;
    while(cin >> n){
        for(int i = 0;i < n;i++){
            cin >> v[i] >> k[i];
        }
        memset(dp, 0, sizeof(dp));
        for(int i = 0;i < n;i++){
            for(int j = 0;j <= 100;j++){
                if(j < v[i]) dp[i + 1][j] = dp[i][j];
                else dp[i + 1][j] = max(dp[i][j], dp[i][j - v[i]] + k[i]);
            }
        }
        cout << dp[n][100] << '\n';
    }

    return 0;
}

// capacity optimized version
// (2ms, 368KB)
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int v[10000], k[10000];
int dp[10000];
int main(){
    IOS
    int n;
    while(cin >> n){
        memset(dp, 0, sizeof(dp));
        for(int i = 0;i < n;i++)
            cin >> v[i] >> k[i];

        for(int i = 0;i < n;i++){
            for(int j = 100;j >= v[i];j--){
                dp[j] = max(dp[j], dp[j - v[i]] + k[i]);
            }
        }
        cout << dp[100] << '\n';
    }

    return 0;
}
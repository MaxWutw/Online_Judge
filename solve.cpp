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
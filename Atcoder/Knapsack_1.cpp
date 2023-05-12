// dp, optimized
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll v[105], w[105], dp[100005];
int main(){
    IOS
    int n, weight;
    cin >> n >> weight;
    for(int i = 0;i < n;i++) cin >> w[i] >> v[i];
    dp[0] = 0;
    for(int i = 0;i < n;i++){
        for(int j = weight;j >= 1;j--){
            if(j - w[i] >= 0)
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[weight] << '\n';

    return 0;
}
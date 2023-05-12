// dp, optimized
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll arr[1000005], dp[1000005];
int main(){
    IOS
    int n, x;
    cin >> n >> x;
    for(int i = 0;i < n;i++) cin >> arr[i];
    dp[0] = 1;
    for(int i = 0;i < n;i++){
        for(int j = 1;j <= x;j++){
            if(j - arr[i] >= 0){
                dp[j] += dp[j - arr[i]];
                dp[j] %= mod;
            }
        }
    }
    cout << dp[x] << '\n';

    return 0;
}
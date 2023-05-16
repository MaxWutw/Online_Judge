// dp
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll arr[105], dp[1000005];
const ll mod = 1e9 + 7;
int main(){
    IOS
    int n, x;
    cin >> n >> x;
    for(int i = 0;i < n;i++) cin >> arr[i];
    dp[0] = 1;
    for(int i = 1;i <= x;i++){
        for(int j = 0;j < n;j++){
            if(i - arr[j] >= 0){
                dp[i] += dp[i - arr[j]];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[x] << '\n';

    return 0;
}
// dp
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll arr[100005], dp[100005];
int main(){
    IOS
    ll n;
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> arr[i];
    dp[0] = arr[0];
    for(int i = 1;i < n;i++)
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    int m = 0;
    for(int i = 1;i < n;i++){
        if(dp[i] > dp[m]){
            m = i;
        }
    }
    cout << dp[m] << '\n';

    return 0;
}

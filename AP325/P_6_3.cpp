// dp
// warning:在吳邦一教授的講義裡是使用2 < n <= 1e5的測資範圍，但在中一中的judge中則是n <= 1e5的範圍，務必注意!
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    // freopen("P_6_3_1.in", "r", stdin);
    int n;
    cin >> n;
    ll arr[100005];
    for(int i = 0;i < n;i++) cin >> arr[i];
    if(n == 1){
        cout << arr[0] << '\n';
        return 0;
    }
    ll dp[100005];
    dp[0] = arr[0];
    dp[1] = arr[1];
    dp[2] = arr[2] + min(dp[0], dp[1]);
    for(int i = 3;i < n;i++){
        dp[i] = min(min(dp[i - 3], dp[i - 2]), dp[i - 1]) + arr[i];
    }
    cout << min(dp[n - 1], dp[n - 2]) << '\n'; 

    return 0;
}

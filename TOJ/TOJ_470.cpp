// dp
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n;
    while(cin >> n){
        int arr[1000005];
        for(int i = 0;i < n;i++) cin >> arr[i];
        int dp[1000005];
        dp[0] = max(0, arr[0]), dp[1] = max({arr[0], arr[1], 0});
        for(int i = 2;i < n;i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
        }
        cout << dp[n - 1] << '\n';
    }

    return 0;
}
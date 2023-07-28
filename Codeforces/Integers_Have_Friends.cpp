#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int t, arr[N], dp[31][N];
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
void sparse_table(int n){
    for(int i = 1;i <= 31;i++){
        for(int j = 0;(j + (1LL << (i - 1))) < n - 1;j++){
            if(j + (1LL << i) - 1 < n - 1)
                dp[i][j] = gcd(dp[i - 1][j], dp[i - 1][j + (1LL << (i - 1))]);
        }
    }
}
int query(int l, int r){
    int idx = __lg(r - l + 1); 
    return gcd(dp[idx][l], dp[idx][r - (1LL << idx) + 1]);
}
signed main(){
    IOS
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0;i < n;i++) cin >> arr[i];
        if(n == 1){
            cout << 1 << '\n';
            continue;
        }
        int ans = 1, left = 0, right = 1;
        for(int i = 1;i < n;i++){
            dp[0][i - 1] = abs(arr[i] - arr[i - 1]);
        }
        sparse_table(n);
        for(int right = 0;right < n - 1;right++){
            while(left < right && query(left, right) == 1) left++;
            if(query(left, right) > 1) ans = max(ans, right - left + 2);
        }
        cout << ans << '\n';
    }

    return 0;
}
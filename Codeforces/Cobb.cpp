// brute force, specicial trick, remember to add 0LL and 1LL
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n + 1);
        ll ans = -1e18;
        for(int i = 0;i < n;i++) cin >> arr[i];
        for(int i = max(0LL, n - 2 * k - 1);i < n;i++){
            for(int j = i + 1;j < n;j++){
                ans = max(ans,1LL * (i + 1) * (j + 1) - 1LL * k * (arr[i] | arr[j]));
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
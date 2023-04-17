// sliding window
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    ll n, k, arr[200005];
    cin >> n >> k;
    for(int i = 0;i < n;i++) cin >> arr[i];
    ll idx = 0, cnt = 0, inc = 0, ans = 0;
    unordered_map<ll, ll> m;
    // m[idx] = 1;
    while(idx < n){
        while(inc < n && cnt + (m[arr[inc]] == 0) <= k){
            m[arr[inc]]++;
            cnt += (m[arr[inc]] == 1);
            inc++;
        }
        ans += (inc - idx);
        cnt -= (m[arr[idx]] == 1);
        m[arr[idx]]--;
        idx++;
    }
    cout << ans << '\n';

    return 0;
}
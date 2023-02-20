#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll p[200005], h[200005];
int main(){
    IOS
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> h[i];
    for(int i = 1;i <= n;i++) cin >> p[i];
    ll ans = 0;
    map<int, int> m;
    m[h[1]] = 1;
    for(int i = 1;i <= n;i++){
        auto it = m.upper_bound(p[i] + h[i]);
        if(it == m.end()) ans += i - 1;
        else ans += (i - it->second - 1);
        auto iter = m.upper_bound(h[i]);
        m.erase(m.begin(), iter);
        m[h[i]] = i;
    }
    cout << ans << '\n';

    return 0;
}
// 60%
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll n, k, a[500005], block[500005];
int query(int l, int r){
    ll ans = -1;
    if(l/k == r/k){
        for(int i = l;i <= r;i++)
            ans = max(ans, a[i]);
        return ans;
    }
    for(int i = l;i <= r;i++){
        if(i/k != l/k) break;
        ans = max(ans, a[i]);
    }
    for(int i = l/k + 1;i < r/k;i++) ans = max(ans, block[i]);
    for(int i = r;i >= l;i--){
        if(i/k != r/k) break;
        ans = max(ans, a[i]);
    }
    return ans;
}
int main(){
    IOS
    cin >> n;
    k = sqrt(n);
    memset(block, 0, sizeof(block));
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) block[i/k] = max(a[i], block[i/k]);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(b < a) swap(a, b);
        cout << query(a, b) << '\n';
    }

    return 0;
}
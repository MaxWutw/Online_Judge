#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll n, m, k, arr[(ll)5e5 + 5], block[(ll)5e5 + 5];
ll query(int l, int r){
    ll ans = -1;
    for(int i = l;i <= r;i++){
        if(i / k != l / k) break;
        ans = max(ans, arr[i]);
    }
    for(int i = r;i >= l;i--){
        if(i / k != r / k) break;
        ans = max(ans, arr[i]);
    }
    for(int i = l / k + 1;i < r / k;i++){
        ans = max(ans, block[i]);
    }
    return ans;
}
int main(){
    IOS
    memset(block, 0, sizeof(block));
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    k = sqrt(n);
    for(int i = 0;i < n;i++) block[i / k] = max(block[i / k], arr[i]);
    cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        if(r < l) swap(l, r);
        cout << query(--l, --r) << '\n';
    }

    return 0;
}
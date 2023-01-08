#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int n, k;
ll p[500005], pre[500005];
ll cut(int l, int r, int level){
    if(level >= k || r - l < 3) return 0;
    int mid = 0;
    for(int i = 0;i < n;i++){
        
    }
    return leng + cut(l + 1, mid - 1, level + 1) + cut(mid + 1, r - 1, level + 1);
}
int main(){
    IOS
    cin >> n >> k;
    for(int i = 0;i < n;i++) cin >> p[i];
    ll ans = cut(0, n - 1, 0);
    cou << ans << '\n';

    return 0;
}
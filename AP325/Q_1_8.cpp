// recursion
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll n, p, arr[30], ans = 0;
void rec(ll num, int cnt){
    if(cnt >= n){
        if(num < p) ans = max(ans, num);
        return;
    }
    rec(num + arr[cnt], cnt + 1);
    rec(num, cnt + 1);
    return;
}
int main(){
    IOS
    cin >> n >> p;
    for(int i = 0;i < n;i++) cin >> arr[i];
    rec(0, 0);
    cout << ans << '\n';

    return 0;
}
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll x, y, p;
ll ans;
int fast(ll x, ll y, ll p){
    ll tmp = 1, exp = x;
    while(y > 0){
        if(y & 1) tmp = (tmp * exp) % p;
        y >>= 1;
        exp = (exp * exp) % p;
    }
    return tmp;
}
int main(){
    IOS
    cin >> x >> y >> p;
    ans = fast(x, y, p);
    cout << ans << '\n';

    return 0;
}
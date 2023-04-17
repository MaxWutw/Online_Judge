// Meet in the Middle
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll n, x, arr[50];
vector<ll> vec;
ll ans = 0;
void rec(ll num, ll idx){
    if(num > x) return;
    if(idx == (n / 2 + 1)){
        vec.push_back(num);
        return;
    }
    rec(num + arr[idx], idx + 1);
    rec(num, idx + 1);
}
void rec2(ll num, ll idx){
    if(num > x) return;
    if(idx >= n){
        ans += upper_bound(vec.begin(), vec.end(), x - num) - lower_bound(vec.begin(), vec.end(), x - num);
        return;
    }
    rec2(num + arr[idx], idx + 1);
    rec2(num, idx + 1);
}
int main(){
    IOS
    cin >> n >> x;
    for(int i = 0;i < n;i++) cin >> arr[i];
    rec(0, 0);
    sort(vec.begin(), vec.end());
    rec2(0, n / 2 + 1);
    cout << ans << '\n';

    return 0;
}
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll n, p;
ll a[50], b[50];
ll fast_pow(int base, int exp){
    if(exp == 0) return 1;
    if(exp & 1) return (fast_pow(base, exp - 1) * base) % p;
    ll tmp = fast_pow(base, exp >> 1);
    return (tmp * tmp) % p;
}
ll sa[1 << 19], sb[1 << 19];
ll num[1 << 19], sb_cnt = 1;
int sub(ll (&arr)[50], ll (&product)[1 << 19], int leng){
    int si = 0;
    for(int i = 0;i < leng;i++){
        for(int j = 0;j < si;j++){
            product[j + si] = (product[j] * arr[i]) % p;
        }
        product[si + si] = arr[i];
        si += si + 1;
    }
    return si;
}
int main(){
    IOS
    cin >> n >> p;
    int len_a = n / 2, len_b = n - len_a;
    for(int i = 0;i < len_a;i++) cin >> a[i];
    for(int i = 0;i < len_b;i++) cin >> b[i];
    int len_sa = sub(a, sa, len_a);
    int len_sb = sub(b, sb, len_b);
    sort(sb, sb + len_sb);
    num[0] = 1;
    for(int i = 1;i < len_sb;i++){
        if(sb[i] != sb[i - 1]){
            sb[sb_cnt] = sb[i];
            num[sb_cnt] = 1;
            sb_cnt++;
        }
        else num[sb_cnt - 1]++;
    }
    ll ans = (sb[0] == 1) ? num[0] % p : 0;
    for(int i = 0;i < len_sa;i++){
        if(sa[i] == 1) ans = (ans + 1) % p;
        ll st = fast_pow(sa[i], p - 2);
        int it = lower_bound(sb, sb + sb_cnt, st) - sb;
        if(it <= sb_cnt && sb[it] == st){
            ans = (ans + num[it]) % p;
        }
    }
    cout << ans << '\n';

    return 0;
}
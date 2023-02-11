#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll n, p;
ll a[1 << 20], b[1 << 20], sa[1 << 20], sb[1 << 20];
int sub(ll (&arr)[1 << 20], ll (&add)[1 << 20], int leng){
    int si = 0;
    for(int i = 0;i < leng;i++){
        for(int j = 0;j < si;j++){
            add[si + j] = add[j] + arr[i];
        }
        add[si + si] = arr[i];
        si += si + 1;
    }
    return si;
}
int main(){
    IOS
    cin >> n >> p;
    int len_a = n >> 1, len_b = n - len_a;
    for(int i = 0;i < len_a;i++) cin >> a[i];
    for(int i = 0;i < len_b;i++) cin >> b[i];
    int len_sa = sub(a, sa, len_a), len_sb = sub(b, sb, len_b);
    sort(sb, sb + len_sb);
    int sb_idx = 0;
    for(int i = 1;i < len_sb;i++){
        if(sb[i] != sb[i - 1]){
            sb[sb_idx] = sb[i];
            sb_idx++;
        }
    }
    ll best = -1;
    for(int i = 0;i < len_sa;i++){
        int it = lower_bound(sb, sb + sb_idx, p - sa[i]) - sb;
        if(sb[it] == (p - sa[i])){
            best = sa[i] + sb[it];
            break;
        }
        if(it >= 0){
            best = max(sb[it - 1] + sa[i], best);
        }
    }
    cout << best << '\n';

    return 0;
}
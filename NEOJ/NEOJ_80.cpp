// segment treeeeeeeeeeeeeee
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
#define int long long
#define lowbit(x) x&(-x)
#define L(x) (x << 1)
#define R(x) ((x << 1) | 1)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int N = 1e6 + 5;
int t, n, arr[N], seg[N * 4 + 5];
void build(int pos, int l, int r){
    if(r == l){
        seg[pos] = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(L(pos), l, mid);
    build(R(pos), mid + 1, r);
    seg[pos] = min(seg[L(pos)], seg[R(pos)]);
}
ll query(int pos, int l, int r, int ql, int qr){
    if(ql <= l && qr >= r) return seg[pos];
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(L(pos), l, mid, ql, qr);
    else if(ql > mid) return query(R(pos), mid + 1, r, ql, qr);
    else return min(query(L(pos), l, mid, ql, qr), query(R(pos), mid + 1, r, ql, qr));
    // return min(query(L(pos), l, mid, ql, qr), query(R(pos), mid + 1, r, ql, qr));
}
void update(int pos, int l, int r, int idx, int val){
    if(r == l){
        seg[pos] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if(idx <= mid) update(L(pos), l, mid, idx, val);
    else update(R(pos), mid + 1, r, idx, val);
    seg[pos] = min(seg[L(pos)], seg[R(pos)]);
}
signed main(){
    IOS
    // memset(seg, 0, sizeof(seg));
    for(int i = 1;i <= 4 * N;i++) seg[i] = INF;
    cin >> t >> n;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    build(1, 1, n);
    while(t--){
        int c;
        cin >> c;
        if(c == 1){
            int x, y;
            cin >> x >> y;
            x++, y++;
            cout << query(1, 1, n, x, y) << '\n';
        }
        else{
            int x, y;
            cin >> x >> y;
            x++;
            update(1, 1, n, x, y);
        }
    }

    return 0;
}
// 6 5
// 2 3 5 1 4
// 1 0 1
// 1 2 4 
// 2 0 5 
// 2 2 2
// 1 0 1
// 1 2 4
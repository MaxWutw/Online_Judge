#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define L(x) (x << 1)
#define R(x) ((x << 1) | 1)
using namespace std;
typedef long long ll;
ll seg[500005 << 2], lazy[500005 << 2];
int n, q;
void init(){
    memset(seg, 0, sizeof(seg));
    memset(lazy, 0, sizeof(lazy));
}
void build(int x, int l, int r){
    if(l == r){
        cin >> seg[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(L(x), l, mid);
    build(R(x), mid + 1, r);
    seg[x] = seg[L(x)] + seg[R(x)];
}
void push(int pos, int size){
    lazy[L(pos)] += lazy[pos];
    lazy[R(pos)] += lazy[pos];
    seg[pos] = seg[pos] + lazy[pos] * size;
    lazy[pos] = 0;
}
void modify(int x, int l, int r, int ql, int qr, int val){
    if(r <= l || ql >= r || qr <= l) return;
    if(ql <= l && qr >= r){
        lazy[x] += val;
        return;
    }
    int mid = (l + r) >> 1;
    modify(L(x), l, mid, ql, qr, val);
    modify(R(x), mid + 1, r, ql, qr, val);
    seg[x] = seg[L(x)] + (mid - l) * lazy[L(x)] + seg[R(x)] + (r - mid) * lazy[R(x)];
}
ll query(int x, int l, int r, int ql, int qr){
    if(r <= l || ql >= r || qr <= l) return 0;
    if(ql <= l && qr >= r) return seg[x] + lazy[x] * (r - l);
    push(x, (r - l));
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(L(x), l, mid, ql, qr);
    else if(ql > mid) return query(R(x), mid + 1, r, ql, qr);
    return query(L(x), l, mid, ql, mid) + query(R(x), mid + 1, r, mid + 1, qr);
}
int main(){
    IOS
    init();
    cin >> n;
    build(1, 1, n);
    cin >> q;
    while(q--){
        int v, x, y, k;
        cin >> v;
        if(v == 1){
            cin >> x >> y >> k;
            modify(1, 1, n, x, y, k);
        }
        else{
            cin >> x >> y;
            ll ans = query(1, 1, n, x, y);
            cout << ans << '\n';
        }
    }

    return 0;
}
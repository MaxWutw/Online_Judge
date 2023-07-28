// Segment Tree
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define L(x) (x << 1)
#define R(x) ((x << 1) | 1)
using namespace std;
typedef long long ll;
int n, m;
ll seg[500005 << 2];
struct Node{
    int left, right;
    int tag;
    int value;
};
ll pull(int x){
    return seg[x] = max(seg[L(x)], seg[R(x)]);
}
void build(int x, int l, int r){
    if(l == r){
        cin >> seg[x];
        return;
    }
    int mid = (l + r) >> 1;
    build(L(x), l, mid);
    build(R(x), mid + 1, r);
    pull(x);
}
void update(int x, int l, int r, int pos, int val){
    if(l == r){
        seg[x] += val;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos >= mid) update(L(x), l, mid, pos, val);
    else update(R(x), mid + 1, r, pos, val);
    pull(x);
}
ll query(int x, int l, int r, int ql, int qr){
    if(ql <= l && qr >= r)
        return seg[x];
    ll ret = 0;
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(L(x), l, mid, ql, qr);
    else if(ql > mid) return query(R(x), mid + 1, r, ql, qr);
    return max(query(L(x), l, mid, ql, mid), query(R(x), mid + 1, r, mid + 1, qr));
}
int main(){
    IOS
    cin >> n;
    build(1, 1, n);
    cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        if(l > r) swap(l, r);
        cout << query(1, 1, n, l, r) << '\n';
    }

    return 0;
}


// 60%
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

// sparse table
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n, m, arr[N], dp[35][N];
void sparse_table(int n){
    for(int i = 1;i <= 31;i++){
        for(int j = 0;(j + (1LL << (i - 1))) < n;j++){
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + (1LL << (i - 1))]);
        }
    }
}
int query(int l, int r){
    int idx = __lg(r - l + 1);
    return max(dp[idx][l], dp[idx][r - (1LL << idx) + 1]);
}
int main(){
    IOS
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    cin >> m;
    for(int i = 0;i < n;i++) dp[0][i] = arr[i];
    sparse_table(n);
    while(m--){
        int l, r;
        cin >> l >> r;
        if(l > r) swap(l, r);
        l--, r--;
        cout << query(l, r) << '\n';
    }

    return 0;
}
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
const int N = 1e5 + 5;
int n, q, arr[N];
struct Node{
    int right, left, mx, sum, ans;
}seg[N * 4 + 5];
void build(int pos, int l, int r){
    if(l == r){
        seg[pos] = {arr[l], arr[l], arr[l], arr[l]};
        return;
    }
    int mid = (l + r) >> 1;
    build(L(pos), l, mid);
    build(R(pos), mid + 1, r);
    modify(seg[pos], seg[L(pos)], seg[R(pos)]);
}
void modify(int pos, int l, int r, int idx, int val){

}
void query(int pos, int l, int r, int ql, int qr){

}
signed main(){
    IOS
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << query(1, 1, n, a, b);
    }

    return 0;
}
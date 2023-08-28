// dp, BIT
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
#define int long long
#define lowbit(x) x&(-x)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int N = 2e5 + 5;
int n, bit[(N * 2) + 10];
struct Project{
    int l, r, p;
    bool operator <(const Project &num){
        return l < num.l;
    }
};
void update(int val, int idx){
    for(int i = idx;i <= 2 * N;i += lowbit(i)){
        bit[i] = max(val, bit[i]);
    }
}
int query(int idx){
    int res = 0;
    for(int i = idx;i > 0;i -= lowbit(i)){
        res = max(res, bit[i]);
    }
    return res;
}
Project arr[N];
vector<int> b;
signed main(){
    IOS
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> arr[i].l >> arr[i].r >> arr[i].p;
        b.push_back(arr[i].l);
        b.push_back(arr[i].r);
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for(int i = 1;i <= n;i++){
        arr[i].l = lower_bound(b.begin(), b.end(), arr[i].l) - b.begin() + 1;
        arr[i].r = lower_bound(b.begin(), b.end(), arr[i].r) - b.begin() + 1;
    }
    sort(arr, arr + n + 1);
    for(int i = 1;i <= n;i++){
        int num = query(arr[i].l - 1);
        update(arr[i].p + num, arr[i].r);
    }
    cout << query(2 * N) << '\n';

    return 0;
}

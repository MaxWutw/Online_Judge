// Mo's Algorithm
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;
ll n, q, b, arr[N], cnt[N], ans[N], tol = 0;
vector<int> dis;
struct Query_base{
    ll l, r, id;
    bool operator < (const Query_base a){
        return (l / b == a.l / b ? r < a.r : l / b < a.l / b);
    }
};
ll discretization(int x){
    return lower_bound(dis.begin(), dis.end(), x) - dis.begin(); // discretization
}
void add(int x){
    if(cnt[x] == 0) tol++;
    cnt[x]++;
}
void remove(int x){
    if(cnt[x] == 1) tol--;
    cnt[x]--;
}
int main(){
    IOS
    memset(cnt, 0, sizeof(cnt));
    cin >> n >> q;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        dis.push_back(arr[i]);
    }
    sort(dis.begin(), dis.end());
    dis.erase(unique(dis.begin(), dis.end()), dis.end());
    for(int i = 0;i < n;i++) arr[i] = discretization(arr[i]);
    b = sqrt(q);
    vector<Query_base> query;
    query.clear(), query.resize(q);
    for(int i = 0;i < q;i++){
        int ql, qr;
        cin >> ql >> qr;
        --ql, --qr; // change to 0-base
        query[i] = {ql, qr, i};
    }
    sort(query.begin(), query.end());
    int l = 0, r = 0;
    // cnt[arr[0]] = 1;
    add(arr[0]);
    for(auto &q : query){
        while(l > q.l) l--, add(arr[l]); // extend
        while(r < q.r) r++, add(arr[r]); // extend
        while(l < q.l) remove(arr[l]), l++; // diminish
        while(r > q.r) remove(arr[r]), r--; // diminish
        ans[q.id] = tol;
    }
    for(int i = 0;i < q;i++)
        cout << ans[i] << '\n';

    return 0;
}

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
int n, m, sz[N], p[N], ans[N];
pair<int, int> query[N];
int Find(int a){
    if(a == p[a]) return a;
    return p[a] = Find(p[a]);
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(sz[a] < sz[b]){
        sz[b] += sz[a];
        p[a] = p[b];
    }
    else{
        sz[a] += sz[b];
        p[b] = p[a];
    }
}
signed main(){
    IOS
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        sz[i] = 1;
        p[i] = i;
    }
    for(int i = 1;i <= m;i++) cin >> query[i].first >> query[i].second;
    for(int i = m;i >= 1;i++){
        if(Find(query[i].first) != Find(query[i].second)){
            p[query[i].second] = query[i].first;

        }
        else ans[i - 1] = ans[i];
    }

    return 0;
}
// Kruskal's Algorithm
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, m;
vector<pair<int, pair<int, int> > > vec;
ll dsu[N], sz[N];
ll Find(int x){
    if(dsu[x] != x) dsu[x] = Find(dsu[x]);
    return dsu[x];
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(sz[b] > sz[a]) swap(a, b);
    dsu[b] = a;
    sz[a] += sz[b];
}
int main(){
    IOS
    cin >> n >> m;
    for(int i = 1;i <= n;i++) dsu[i] = i;
    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        vec.push_back({c, {a, b}});
    }
    sort(vec.begin(), vec.end());
    ll ans = 0;
    int cnt = 0;
    for(auto e : vec){
        if(Find(e.second.first) == Find(e.second.second)) continue;
        cnt++, ans += e.first;
        Union(e.second.first, e.second.second);
    }
    if(cnt < n - 1) cout << "IMPOSSIBLE" << '\n';
    else cout << ans << '\n';

    return 0;
}

// Prim's algorithm
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, m;
vector<pair<int, int> > vec[N];
int vis[N];
int main(){
    IOS
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
        vec[b].push_back({a, c});
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, 1});
    int cnt = 0;
    ll ans = 0;
    while(!pq.empty()){
        int cur = pq.top().second, w = pq.top().first;
        pq.pop();
        if(vis[cur]) continue;
        vis[cur] = 1;
        ans += w, cnt++;
        for(auto e : vec[cur]){
            if(!vis[e.first]) pq.push({e.second, e.first});
        }
    }
    if(cnt < n - 1) cout << "IMPOSSIBLE" << '\n';
    else cout << ans << '\n';

    return 0;
}


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

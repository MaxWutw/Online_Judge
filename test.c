#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// #define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
int n, m;
const ll INF = 1e17;
void dijkstra(vector<pair<ll, ll> > vec[100005], ll src, ll dis[], ll vis[]){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    for(int i = 1;i <= n;i++){
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[src] = 0;
    pq.push({0, src});
    while(!pq.empty()){
        pair<ll, ll> cur = pq.top();
        ll u = cur.second, weight = cur.first;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto i : vec[u]){
            ll v = i.first, w = i.second;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}
int main(){
    IOS
    while(cin >> n >> m){
        vector<pair<ll, ll> > vec[100005];
        unordered_map<string, ll> mp;
        ll idx = 1;
        for(int i = 0;i < m;i++){
            string str1, str2;
            int d;
            cin >> str1 >> str2 >> d;
            if(mp[str1] == 0){
                mp[str1] = idx;
                idx++;
            }
            if(mp[str2] == 0){
                mp[str2] = idx;
                idx++;
            }
            vec[mp[str1]].push_back({mp[str2], d});
            vec[mp[str2]].push_back({mp[str1], d});
        }
        string str1, str2;
        cin >> str1 >> str2;
        if(mp[str1] == 0){
            cout << -1 << '\n';
            continue;
        }
        if(mp[str2] == 0){
            cout << -1 << '\n';
            continue;
        }
        ll source = mp[str1], des = mp[str2], dis1[100005], dis2[100005], vis[100005];
        dijkstra(vec, source, dis1, vis);
        dijkstra(vec, des, dis2, vis);
        if(dis1[des] == INF){
            cout << -1 << '\n';
            continue;
        }
        ll ans = INF;
        for(int i = 1;i < idx;i++){
            for(auto j : vec[i]){
                int u = i, v = j.first;
                cout << u << ' ' << v << ' ' << j.second << '\n';
                ll discount = j.second;
                if(ans > (dis1[u] + dis2[v] + discount / 2))
                    ans = (dis1[u] + dis2[v] + discount / 2);
            }
        }
        // cout << dis1[des] << ' ' << dis2[source] << '\n';
        if(ans >= INF) cout << -1 << '\n';
        else cout << ans << '\n';
        // else cout << dis[des] << '\n';
    }

    return 0;
}
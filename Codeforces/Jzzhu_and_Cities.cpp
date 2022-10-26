#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
vector<pair<int, int> > adj[300005];
int dis[200005];
int main(){
    IOS
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0;i < m;i++){
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }
    while(k--){
        memset(dis, INF, sizeof(dis));
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
        int a, b;
        cin >> a >> b;
        dis[a] = 0;
        pq.push({0, a});
        while(!pq.empty()){
            pair<int, int> cur = pq.top();
            pq.pop();
            for(auto i : adj[cur.second]){
                if(cur.first + i.first < dis[i.second]){
                    dis[i.second] = cur.first + i.first;
                    pq.push({dis[i.second], i.second});
                }
            }
        }
        cout << dis[b] << '\n';
    }

    return 0;
}

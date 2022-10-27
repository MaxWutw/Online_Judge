#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n, m;
vector<vector<pair<int, int> > > adj;
int main(){
    IOS
    cin >> n >> m;
    adj.resize(n + 10);
    int dis[n + 10];
    memset(dis, INF, sizeof(dis));
    for(int i = 0;i < m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
    }
    queue<int> q;
    bool inque[n + 10];
    memset(inque, 0, sizeof(inque));
    inque[0] = true;
    dis[0] = 0; 
    q.push(0);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        inque[cur] = false;
        for(auto e : adj[cur]){
            if(dis[e.first] > dis[cur] + e.second){
                dis[e.first] = dis[cur] + e.second;
                if(!inque[e.first]){
                    inque[e.first] = true;
                    q.push(e.first);
                }
            }
        }
    }
    cout << dis[n - 1] << '\n';

    return 0;
}

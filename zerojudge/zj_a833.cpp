// SPFA
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n, m;
vector<pair<int, int> > adj[500005];
int dis[500005];
bool inque[500005];
int main(){
    IOS
    cin >> n >> m;
    memset(dis, INF, sizeof(dis));
    for(int i = 0;i < m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        // adj[u].push_back({v, w});
    }
    queue<int> q;
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
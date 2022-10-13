// g++ -std=c++11 tmp.cpp -o tmp
// ./tmp.o

// version 1: Prim's algorithm
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int n, m, dis[10005], parent[10005];
bool visited[10005] = {false};
vector<pair<int, int> > adj[100005];
int main(){
    IOS
    // freopen("input.in", "r", stdin);
    cin >> n >> m;
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    memset(parent, -1, sizeof(parent));
    for(int i = 0;i < m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int start = 0;
    dis[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({dis[start], start});
    while(!pq.empty()){
        pair<int, int> cur = pq.top();
        pq.pop();
        if(visited[cur.second]) continue;
        visited[cur.second] = true;
        for(auto i : adj[cur.second]){
            if(visited[i.first]) continue;
            if(dis[i.first] > i.second){
                dis[i.first] = i.second;
                parent[i.first] = cur.second;
                pq.push({dis[i.first], i.first});
            }
        }
    }
    int cost = 0, err = 0;
    for(int i = 0;i < n;i++){
        if(dis[i] < 0x3f3f3f3f) cost += dis[i];
        else err++;
    }
    cout << (err ?  -1 : cost) << "\n";
    // for(int i = 0;i < n;i++) cout << dis[i] << ' ';

    return 0;
}


// version 2: Kruskal's algorithm
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int parent[10005];
struct Edge{
    int u, v, w;
    bool operator < (Edge &b){
        return w < b.w;
    }
};
int query(int a){
    if(parent[a] == -1) return a;
    return parent[a] = query(parent[a]);
}
bool merge(int a, int b){
    int r1 = query(a);
    int r2 = query(b);
    if(r1 == r2) return false;
    if(parent[r1] < parent[r2]) parent[r2] = r1;
    else parent[r1] = r2;
    return true;
}
int main(){
    IOS
    int n, m;
    memset(parent, -1, sizeof(parent));
    cin >> n >> m;
    vector<Edge> adj;
    for(int i = 0;i < m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({u, v, w});
    }
    sort(adj.begin(), adj.end());
    // for(int i = 0;i < m;i++) cout << adj[i].w << ' ';
    int cost = 0, n_edge = 0;
    for(Edge e : adj){
        if(merge(e.u, e.v)){
            cost += e.w;
            n_edge++;
        }
    }
    if(n_edge == n - 1) cout << cost << '\n';
    else cout << -1 << '\n';

    return 0;
}
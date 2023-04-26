// unsolved
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    vector<int> adj[100005];
    int indegree[100005];
    memset(indegree, 0, sizeof(indegree));
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;
        indegree[v]++;
        adj[u].push_back(v);
    }
    queue<int> q;
    for(int i = 0;i < n;i++){
        if(!indegree[i]) q.push(i);
    }
    int ans = 0, cnt[100005];
    memset(cnt, 0, sizeof(cnt));
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int edge : adj[u]){
            cnt[edge]++;
            if(!--indegree[edge]) q.push(edge);
        }
    }
    cout << ans << '\n';

    return 0;
}
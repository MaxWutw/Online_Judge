// dfs + adjacency list
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int n, m, x, y;
bool visited[10005];
vector<int> adj[10005];
void dfs(int depth){
    for(int i : adj[depth]){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i);
    }
}
int main(){
    IOS
    while(cin >> n >> m){
        memset(visited, 0, sizeof(visited));
        for(int i = 0;i < m;i++){
            int a, b;
            cin >> a >> b;
            if(a == b) continue;
            a--, b--;
            adj[a].push_back(b);
        }
        cin >> x >> y;
        x--, y--;
        dfs(x);
        cout << (visited[y] ? "Yes!!!\n" : "No!!!\n");
        for(int i = 0;i < n;i++)
            adj[i].clear();
    }

    return 0;
}

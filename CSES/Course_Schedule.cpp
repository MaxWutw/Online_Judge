// topological sort by dfs
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int vis[200005];
vector<int> vec[200005], top;
bool dfs(int st){
    vis[st] = 2;
    bool judge = true;
    for(auto e : vec[st]){
        if(vis[e] == vis[st]) return false;
        else if(!vis[e]) judge &= dfs(e);
    }
    vis[st] = 1;
    top.push_back(st);
    return judge;
}
int main(){
    IOS
    memset(vis, 0, sizeof(vis));
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
    }
    bool judge = true;
    for(int i = 1;i <= n;i++){
        if(!vis[i]) judge &= dfs(i);
    }
    if(judge){
        for(int i = top.size() - 1;i >= 0;i--) cout << top[i] << ' ';
        cout << '\n';
    }
    else cout << "IMPOSSIBLE" << '\n';

    return 0;
}

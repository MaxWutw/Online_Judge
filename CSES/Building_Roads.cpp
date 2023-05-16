// dfs
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
bool vis[200005];
vector<int> vec[200005];
void dfs(int st){
    vis[st] = true;
    for(auto e : vec[st]){
        if(!vis[e]){
            dfs(e);
        }
    }
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
        vec[b].push_back(a);
    }
    vector<pair<int, int> > ans;
    dfs(1);
    for(int i = 2;i <= n;i++){
        if(!vis[i]){
            ans.push_back({1, i});
            dfs(i);
        }
    }
    cout << ans.size() << '\n';
    for(auto it : ans) cout << it.first << ' ' << it.second << '\n';

    return 0;
}
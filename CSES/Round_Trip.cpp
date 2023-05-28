// detect cycle
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
vector<int> vec[200005], ans;
int vis[100005];
stack<int> s;
void dfs(int st, int pre){
    vis[st] = 2;
    s.push(st);
    for(auto e : vec[st]){
        if(!vis[e]) dfs(e, st);
        if(vis[e] == 2 && e != pre && ans.empty()){
            ans.push_back(e);
            while(!s.empty()){
                ans.push_back(s.top());
                if(s.top() == e) break;
                s.pop();
            }
            reverse(ans.begin(), ans.end());
            return;
        }
    }
    vis[st] = 1;
    if(!s.empty()) s.pop();
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
    for(int i = 1;i <= n;i++)
        if(!vis[i]) 
            dfs(i, i);
    if(!ans.empty()){
        cout << ans.size() << '\n';
        for(auto i : ans) cout << i << ' ';
        cout << '\n';
    }
    else cout << "IMPOSSIBLE" << '\n';

    return 0;
}

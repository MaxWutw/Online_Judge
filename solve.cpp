#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
vector<int> vec[200005], ans;
int vis[100005];
stack<int> s;
void dfs(int st){
    vis[st] = 2;
    s.push(st);
    for(auto e : vec[st]){
        if(!vis[st]) dfs(e);
        if(vis[e] == 2 && ans.empty()){
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
    if()
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

    return 0;
}

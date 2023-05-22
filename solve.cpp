#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int n, m, p, k;
vector<pair<int, int> > mem[20005];
bool vis[20005], ill[200005];
int team[20005];
bool dfs(int st, int idx){
    vis[st] = true;
    bool judge = true;
    for(auto e : mem[st]){
        if(e.second > idx || ill[e.second])
            continue;
        if(vis[e.first] && team[st] == team[e.first]) return false;
        if(!vis[e.first]){
            team[e.first] = 1 + (1 == team[e.first]);
            judge = dfs(e.first, idx);
        }
    }
    return judge;
}
bool check(int idx){
    memset(vis, 0, sizeof(vis));
    memset(team, 0, sizeof(team));
    for(int i = 0;i < n;i++){
        if(!vis[i]){
            team[i] = 1;
            if(!dfs(i, idx))
                return false;
        }
    }
    return true;
}
int main(){
    IOS
    memset(ill, 0, sizeof(ill));
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        mem[a].push_back({b, 0});
        mem[b].push_back({a, 0});
    }
    cin >> p >> k;
    for(int i = 0;i < p;i++){
        for(int j = 0;j < k;j++){
            int a, b;
            cin >> a >> b;
            mem[a].push_back({b, i});
            mem[b].push_back({a, i});
        }
        
    }
    vector<int> ans;
    for(int i = 0;i < 3 && !check(p);i++){
        int l = 0, r = p;
        while(l < r){
            int mid = (l + r) >> 1;
            if(check(mid))
                l = mid + 1;
            else
                r = mid;
        }
        if(r > 0){
            ill[r] = true;
            ans.push_back(r);
        }
    }
    for(auto i : ans) cout << i << ' ';
    cout << '\n';

    return 0;
}

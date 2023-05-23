#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll n, m, p, k;
vector<pair<ll, ll> > mem[200005];
bool vis[200005], ill[200005];
ll team[200005];
bool dfs(int st, int idx){
    vis[st] = true;
    bool judge = true;
    for(auto e : mem[st]){
        if(e.second > idx || ill[e.second])
            continue;
        if(vis[e.first] && team[e.first] == team[st]) return false;
        if(!vis[e.first]){
            team[e.first] = 1 + (team[st] == 1);
            judge &= dfs(e.first, idx);
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
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        ll a, b;
        cin >> a >> b;
        mem[a].push_back({b, 0});
        mem[b].push_back({a, 0});
    }
    cin >> p >> k;
    for(int i = 1;i <= p;i++){
        for(int j = 0;j < k;j++){
            ll a, b;
            cin >> a >> b;
            mem[a].push_back({b, i});
            mem[b].push_back({a, i});
        }
    }
    vector<ll> ans;
    for(int i = 0;i < 3 && !check(p);i++){
        int l = 0, r = p;
        while(l < r){
            int mid = (l + r) / 2;
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
    for(auto i : ans) cout << i << '\n';

    return 0;
}

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;
int n;
ll arr[N], dp[N], cost[N];
vector<int> vec[N];
void dfs(int cur, int pre, int depth){
    for(auto &e : vec[cur]){
        if(e == pre) continue;
        dfs(e, cur, depth + 1);
        cost[e] += (depth * arr[cur]);
    }
}
void dfs2(int cur, int pre){
    for(auto &e : vec[cur]){
        if(e == cur) continue;
        dp[e] = dp[cur] + cost[1] - (2 * dp[e]);
        dfs(e, cur);
    }
}
int main(){
    IOS
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    for(int i = 1;i < n;i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(1, 1, 0);
    dfs2(1, 1, 0);
    

    return 0;
}

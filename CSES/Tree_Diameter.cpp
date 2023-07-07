// tree diameter calculated by 2 times dfs
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;
vector<int> vec[N];
ll mx = -1;
int root = -1;
void dfs(int cur, int s, int cnt){
    if(cnt > mx) mx = cnt, root = cur;
    for(auto e : vec[cur]){
        if(e == s) continue;
        dfs(e, cur, cnt + 1);
    }
}
int main(){
    IOS
    int n;
    cin >> n;
    for(int i = 0;i < n - 1;i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(1, 1, 0);
    int r = root;
    root = -1, mx = -1;
    dfs(r, r, 0);
    cout << mx << '\n';

    return 0;
}


// tree dp
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;
int n;
vector<int> vec[N];
int dp[N], ans = -1;
void dfs(int cur, int pre){
    int mx = 0, smx = 0;
    for(auto &e : vec[cur]){
        if(e == pre) continue;
        dfs(e, cur);
        if(dp[e] > mx) smx = mx, mx = dp[e];
        else if(dp[e] > smx) smx = dp[e];
    }
    dp[cur] = mx + 1;
    ans = max(ans, mx + smx);
}
int main(){
    IOS
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for(int i = 0;i < n - 1;i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(1, 1);
    cout << ans << '\n';

    return 0;
}

// DAG DP
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
string str[105];
vector<int> vec[100005];
int dp[100005], ind[100005];
int main(){
    IOS
    int n, m;
    memset(ind, 0, sizeof(ind));
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        ind[b]++;
    }
    queue<int> q;
    for(int i = 1;i <= n;i++){
        if(!ind[i]){
            q.push(i);
            dp[i] = 0;
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto e : vec[cur]){
            ind[e]--;
            dp[e] = max(dp[cur] + 1, dp[e]);
            if(!ind[e]){
                q.push(e);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) ans = max(dp[i], ans);
    cout << ans << '\n';

    return 0;
}

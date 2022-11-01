// dfs
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
vector<pair<char, int> > adj[105];
ll ans = -1;
void dfs(char start, ll sum){
    ans = max(ans, sum);
    for(auto edge : adj[start]){
        dfs(edge.first, sum + edge.second);
    }
}
int main(){
    IOS
    char s;
    cin >> s;
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        char b, e;
        int w;
        cin >> b >> e >> w;
        adj[b].push_back({e, w});
    }
    dfs(s, 0);
    cout << ans << '\n';

    return 0;
}
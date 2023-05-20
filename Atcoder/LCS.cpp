#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll dp[3005][3005];
pair<ll, ll> pre[3005][3005];
int main(){
    IOS
    string s, t;
    cin >> s >> t;
    for(ll i = 0;i < s.size();i++){
        for(ll j = 0;j < t.size();j++){
            if(s[i] == t[j]){
                dp[i + 1][j + 1] = dp[i][j] + 1;
                pre[i + 1][j + 1] = {i, j};
            }
            else if(dp[i][j + 1] >= dp[i + 1][j]){
                dp[i + 1][j + 1] = dp[i][j + 1];
                pre[i + 1][j + 1] = {i, j + 1};
            }
            else{
                dp[i + 1][j + 1] = dp[i + 1][j];
                pre[i + 1][j + 1] = {i + 1, j};
            }
        }
    }
    ll idx1 = s.size(), idx2 = t.size();
    string ans;
    while(idx1 >= 1 && idx2 >= 1){
        if(pre[idx1][idx2] == make_pair(idx1 - 1, idx2 - 1))
            ans += s[idx1 - 1];

        pair<ll, ll> u = pre[idx1][idx2];
        idx1 = u.first;
        idx2 = u.second;
    }
    for(ll i = ans.size() - 1;i >= 0;i--) cout << ans[i];

    return 0;
}
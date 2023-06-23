// dp
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll h[105], s[105], k[105], dp[100005];
ll n, x;
vector<ll> item, page;
int main(){
    IOS
    cin >> n >> x;
    memset(dp, 0, sizeof(dp));
    for(int i = 0;i < n;i++) cin >> h[i];
    for(int i = 0;i < n;i++) cin >> s[i];
    for(int i = 0;i < n;i++){
        cin >> k[i];
        for(int j = 0; ; j++){
            if(k[i] == 0) break;
            if(k[i] >= (1 << j)){
                item.push_back((1 << j) * h[i]);
                page.push_back((1 << j) * s[i]);
                k[i] -= (1 << j);
            }
            else{
                item.push_back(k[i] * h[i]);
                page.push_back(k[i] * s[i]);
                break;
            }
        }
    }
    // for(auto i : item) cout << i << ' ';
    for(ll i = 0;i < item.size();i++){
        for(ll j = x;j >= 0;j--){
            if(j >= item[i]){
                dp[j] = max(dp[j], dp[j - item[i]] + page[i]);
            }
        }
    }
    cout << dp[x] << '\n';

    return 0;
}

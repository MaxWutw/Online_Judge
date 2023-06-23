#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
<<<<<<< HEAD
typedef long long ll;
pair<int, int> arr[200005];
int main(){
    IOS
    int n;
    vector<int> v;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n, [&](pair<int, int> a, pair<int, int> b){return a.first < b.first;});
    for(int i = 0;i < n;i++){
        auto idx = upper_bound(v.begin(), v.end(), arr[i].second) - v.begin();
        if(v.empty() || v.back() <= arr[idx].second) v.push_back(arr[i].second);
        else v[idx] = arr[i].second;
    }
    cout << v.size() << '\n';
=======
typedef long long ll; 
ll arr[1000005], dp[1000005];
int main(){
    IOS
    int n, k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    deque<pair<ll, ll> > dq;
    dq.push_back({0, 0});
    for(int i = 1;i <= n;i++){
        while(dq.size() && dq.front().second < i - k) dq.pop_front();
        if(i <= k)
            dp[i] = arr[i] + ((dq.size() && dq.front().first < 0) ? dq.front().first : 0);
        else dp[i] = arr[i] + dq.front().first;
        while(dq.size() && dq.back().first >= dp[i]) dq.pop_back();
        dq.push_back({dp[i], i});
    }
    ll ans = INF;
    for(int i = n;i >= n - k;i--) ans = min(ans, dp[i]);
    cout << ans << '\n';
>>>>>>> 556b975384d942657ca4680e256dad2599e5d6cc

    return 0;
}
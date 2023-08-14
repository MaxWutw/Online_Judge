#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
#define int long long
#define lowbit(x) x&(-x)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int N = 2e5 + 5;
vector<int> b;
int arr[N + 5], dp[N + 5], lis = 1, n;
int query(int idx){
    int ans = 0;
    for(int i = idx;i > 0;i-=lowbit(i)){
        ans = max(dp[i], ans);
    }
    return ans;
}
void update(int idx, int val){
    for(int i = idx;i <= N;i+=lowbit(i)){
        dp[i] = max(dp[i], val);
    }
}
signed main(){
    IOS
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        b.push_back(arr[i]);
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for(int i = 1;i <= n;i++)
        arr[i] = lower_bound(b.begin(), b.end(), arr[i]) - b.begin() + 1;
    for(int i = 0;i <= N;i++) dp[i] = 0;
    for(int i = 1;i <= n;i++){
        int leng = query(arr[i] - 1) + 1;
        update(arr[i], leng);
    }
    int ans = 1;
    for(int i = 0;i <= N;i++) ans = max(ans, dp[i]);
    cout << ans << '\n';

    return 0;
}

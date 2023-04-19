// greedy, Remember to add long long
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long 
using namespace std;
typedef long long ll;
signed main(){
    IOS
    int n;
    pair<int, int> arr[200005];
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n);
    int ans = 0, tp = 0;
    for(int i = 0;i < n;i++){
        tp += arr[i].first;
        ans += (arr[i].second - tp);
    }
    cout << ans << '\n';

    return 0;
}
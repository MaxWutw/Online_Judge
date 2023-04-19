// greedy
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    IOS
    int n;
    pair<int, int> arr[200005];
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n, [&](pair<int, int> a, pair<int, int> b){return a.second < b.second;});
    int ans = 1, pre = arr[0].second;
    for(int i = 1;i < n;i++){
        if(arr[i].first >= pre){
            ans++;
            pre = arr[i].second;
        }
    }
    cout << ans << '\n';

    return 0;
}
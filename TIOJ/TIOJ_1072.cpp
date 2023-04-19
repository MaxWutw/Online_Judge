// greedy
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n;
    while(cin >> n && n != 0){
        pair<int, int> arr[10005];
        for(int i = 0;i < n;i++){
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr, arr + n, [&](pair<int, int> a, pair<int, int> b){return a.second > b.second;});
        ll ans = 0, tp = 0;
        for(int i = 0;i < n;i++){
            ans += arr[i].first;
            if(ans + arr[i].second > tp)
                tp = (ans + arr[i].second);
        }
        cout << tp << '\n';
    }

    return 0;
}
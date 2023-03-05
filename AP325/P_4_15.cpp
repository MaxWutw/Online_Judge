// L1 distance |a-c|+|b-d|, sweep-line
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n;
    pair<int, int> arr[100005];
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n);
    int min_dis = INF;
    map<int, int> m;
    for(int i = 0;i < n;i++){
        auto it = m.lower_bound(arr[i].second - min_dis);
        while(it != m.end() && it->first <= arr[i].second + min_dis){
            if(it->second < arr[i].first - min_dis){
                it = m.erase(it);
                continue;
            }
            min_dis = min(min_dis, abs(it->second - arr[i].first) + abs(it->first - arr[i].second));
            it++;
        }
        m.insert({arr[i].second, arr[i].first});
    }
    cout << min_dis << '\n';

    return 0;
}
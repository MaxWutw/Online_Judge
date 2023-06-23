#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
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

    return 0;
}

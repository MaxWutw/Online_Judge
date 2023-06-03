#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
pair<ll, ll> arr[200005];
int main(){
    IOS
    ll n;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n);
    vector<ll> v;
    for(int i = 0;i < n;i++){
        if(v.empty() || v.back() <= arr[i].second) v.push_back(arr[i].second);
        else v[upper_bound(v.begin(), v.end(), arr[i].second) - v.begin()] = arr[i].second;
    }
    cout << v.size() << '\n';

    return 0;
}

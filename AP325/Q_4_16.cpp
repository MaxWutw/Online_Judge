#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    return a.first < b.first;
}
int main(){
    IOS
    int n;
    cin >> n;
    pair<ll, ll> order[100005];
    for(int i = 0;i < n;i++) cin >> order[i].first;
    for(int i = 0;i < n;i++) cin >> order[i].second;
    sort(order, order + n, cmp);
    ll timestep = 0, total = 0;
    for(int i = 0;i < n;i++){
        timestep += order[i].first;
        total += (order[i].second - timestep);
    }
    cout << total << '\n';

    return 0;
}
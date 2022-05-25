#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
bool cmp(pair<ll, ll> &a, pair<ll, ll> &b){
    return a.first < b.first;
}
int main(){
    IOS
    int n;
    pair<ll, ll> point[100005];
    cin >> n;
    ll max_x, max_y;
    cin >> max_x >> max_y;
    for(int i = 0;i < n;i++) cin >> point[i].first >> point[i].second;
    sort(point, point + n, cmp);
    pair<ll, ll> last = point[0];
    int total = 0, x = max_x, y = point[0].second;
    for(int i = 0;i < n;i++){
        if(point[i].first <= min_x){

        }
        if(point[i].first == x)
        if(point[i].first > x && point[i].second > last.second){
            total++;
            last = point[i];
        }
    }
    for(int i = 0;i < n;i++){
        if(point[i].first > x)
    }
    cout << total << '\n';

    return 0;
}
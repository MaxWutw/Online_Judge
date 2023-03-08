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

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n, x, y;
    pair<int, int> tp[100005];
    cin >> n;
    cin >> x >> y;
    for(int i = 0;i < n;i++) cin >> tp[i].first >> tp[i].second;
    sort(tp, tp + n);
    stack<pair<int, int> > s;
    bool judge = true;
    int s = 0, t = 0;
    while(s < n && tp[s].second < x) s++;
    while(t < n && tp[t].first < y) t++;
    if(tp[s + 1].first > x || tp[t].second < y){
        cout << -1 << '\n';
        return 0;
    }
    s.push(tp[s]);
    for(int i = s + 1;i < t;i++){
        if(s.top().second < tp[i].first){
            judge = false;
            break;
        }
        if(s.top().second >= tp[i].second) continue;
        s.push(tp[i]);
        if(s.top().second < tp[i].first) s.pop();
    }
    cout << (judge ? s.size() : -1) << '\n';

    return 0;
}
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 1000000007
using namespace std;
typedef long long ll;
pair<int, int> point[100005];
int cal_dis(pair<int, int> &a, pair<int, int> &b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}
int divide(int l, int r){
    if(l == r) return INF;
    if(r - l == 1) return cal_dis(point[l], point[r]);
    int mid = (l + r) / 2;
    int d = min(divide(l, mid), divide(mid + 1, r));
    vector<pair<int, int> > tmp;
    int cnt = 0;
    for(int i = l;i <= r;i++){
        if(abs(point[i].first - point[mid].first) < d) tmp.push_back(point[i]);
    }
    sort(tmp.begin(), tmp.end(), [](pair<int, int> &a, pair<int, int> &b){return a.second < b.second;});
    for(int i = 0;i < tmp.size();i++){
        for(int j = i + 1;j < tmp.size() && abs(tmp[j].second - tmp[i].second) < d;j++){
            d = min(d, cal_dis(tmp[i], tmp[j]));
        }
    }
    return d;
}
int main(){
    IOS
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> point[i].first >> point[i].second;
    sort(point, point + n);
    cout << divide(0, n - 1) << '\n';

    return 0;
}
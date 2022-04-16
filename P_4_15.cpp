// unsolved
// L1 distance |a-c|+|b-d|, sweep-line
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 2147483647
using namespace std;
typedef long long ll;
// pair<int, int> point[100005];
struct Data{
    int first, second;
};
bool cmp(struct Data a, struct Data b){
    return a.first < b.first;
}
int main(){
    IOS
    // freopen("C:\\Users\\admin\\Downloads\\P_15_2.in", "r", stdin);
    int n;
    struct Data point[100005];
    cin >> n;
    cout << n << '\n';
    for(int i = 0;i < n;i++) cin >> point[i].first >> point[i].second;
    sort(point, point + n, cmp);
    multimap<int, int> M;
    int min_d = INF;
    for(int i = 0;i < n;i++){
        auto iter = M.lower_bound(point[i].second - min_d);
        while(iter != M.end() && iter->first <= point[i].second + min_d){ // if iter == M.end represent there is no element in multimap.
            if(iter->second < point[i].first - min_d){
                iter = M.erase(iter); // when multimap remove an iterator, its return next element of multimap
                continue;
            }
            min_d = min(min_d, abs(point[i].first - iter->second) + abs(point[i].second - iter->first));
            iter++;
        }
        M.insert({point[i].second, point[i].first});
    }
    cout << min_d << '\n';

    return 0;
}
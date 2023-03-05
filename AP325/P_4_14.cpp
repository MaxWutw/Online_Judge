#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n;
    cin >> n;
    pair<int, int> coord[100005];
    for(int i = 0;i < n;i++) cin >> coord[i].first;
    for(int i = 0;i < n;i++) cin >> coord[i].second;
    sort(coord, coord + n);
    stack<pair<int, int> > s;
    s.push({INF, INF});
    for(int i = 0;i < n;i++){
        while(s.top().second <= coord[i].second) s.pop();
        s.push(coord[i]);
    }
    cout << s.size() - 1 << '\n';

    return 0;
}
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 2147483647
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}
int main(){
    IOS
    pair<int, int> point[100005];
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> point[i].first;
    for(int i = 0;i < n;i++) cin >> point[i].second;
    sort(point, point + n, cmp);
    stack<int> S;
    S.push(INF);
    for(int i = 0;i < n;i++){
        while(point[i].second >= S.top()) S.pop();
        S.push(point[i].second);
    }
    cout << S.size() - 1 << '\n';

    return 0;
}
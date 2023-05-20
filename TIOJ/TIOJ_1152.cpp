// dfs
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
vector<int> vec[10005];
int ans = 0;
int dfs(int st, int depth){
    pair<int, int> mx{depth, depth};
    for(auto e : vec[st]){
        int tmp = dfs(e, depth + 1);
        if(tmp > mx.first) mx = {tmp, mx.first};
        else if(tmp > mx.second) mx = {mx.first, tmp};
        ans = max(ans, (mx.first + mx.second) - depth * 2);
    }
    return mx.first;
}
int main(){
    IOS
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int tmp;
        while(cin >> tmp && tmp != -1){
            vec[i].push_back(tmp);
        }
    }
    dfs(0, 1);
    cout << ans << '\n';

    return 0;
}

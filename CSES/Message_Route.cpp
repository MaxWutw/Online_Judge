// bfs
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n, m;
    vector<int> vec[200005];
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    int from[200005];
    memset(from, 0, sizeof(from));
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto e : vec[cur]){
            if(from[e] == 0){
                from[e] = cur;
                q.push(e);
            }
        }
    }
    if(from[n] == 0){
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    vector<int> ans;
    int cur = n;
    while(cur != 1){
        ans.push_back(cur);
        cur = from[cur];
    }
    ans.push_back(cur);
    cout << ans.size() << '\n';
    for(int i = ans.size() - 1;i >= 0;i--) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}

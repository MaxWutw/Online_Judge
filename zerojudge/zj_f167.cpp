#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n, m;
    cin >> n >> m;
    vector<int> vec[1005];
    int ind[1005], ans[1005];
    memset(ind, 0, sizeof(ind));
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        ind[b]++;
    }
    queue<int> q;
    for(int i = 1;i <= n;i++){
        if(ind[i] == 0) q.push(i);
    }
    int idx = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans[idx++] = cur;
        for(auto i : vec[cur]){
            ind[i]--;
            if(ind[i] == 0) q.push(i);
        }
    }
    if(idx != n) cout << "NO" << '\n';
    else{
        cout << "YES" << '\n';
        for(int i = 0;i < n;i++) cout << ans[i] << '\n';
    }

    return 0;
}
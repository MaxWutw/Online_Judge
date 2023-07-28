// LCA
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n, q;
vector<int> vec[N];
int p[20][N], depth[N];
void dfs(int cur, int par, int dep){
    depth[cur] = dep;
    p[0][cur] = par;
    for(auto e : vec[cur])
        dfs(e, cur, dep + 1);
}
int main(){
    IOS
    cin >> n >> q;
    for(int i = 2;i <= n;i++){
        int e;
        cin >> e;
        vec[e].push_back(i); // employee is i
    }
    dfs(1, 1, 0);
    for(int i = 1;i < 20;i++){
        for(int j = 1;j <= n;j++){
            p[i][j] = p[i - 1][p[i - 1][j]];
        }
    }
    while(q--){
        int x, k;
        cin >> x >> k;
        if(depth[x] < k){
            cout << "-1" << '\n';
            continue;
        }
        for(int i = 0;i < 20;i++){
            if(k & (1 << i)) x = p[i][x]; 
        }
        cout << x << '\n';
    }

    return 0;
}

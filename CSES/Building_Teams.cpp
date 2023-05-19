// dfs
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
vector<int> vec[200005];
int n, m;
bitset<200005> vis;
int color[200005];
bool judge = true;
void dfs(int st){
    vis[st] = true;
    for(auto e : vec[st]){
        if(color[st] == color[e]){
            judge = false;
            return;
        }
        if(!vis[e]){
            color[e] = 1 + (1 == color[st]);
            dfs(e);
        }
    }
}
int main(){
    IOS
    memset(color, 0, sizeof(color));
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            color[i] = 1;
            dfs(i);
        }
        if(!judge){
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }
    for(int i = 1;i <= n;i++) cout << color[i] << ' ';
    cout << '\n';

    return 0;
}

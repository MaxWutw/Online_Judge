#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int n, m, p, k;
vector<pair<int, int> > mem[20005], ret[20005];
bool vis[20005];
int team[20005];
void dfs(int st){
    vis[st] = true;
    for(auto e : mem[st]){
        dfs(e);
    }
}
int check(){

}
int main(){
    IOS
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        mem[a].push_back({b, 0});
        mem[b].push_back({a, 0});
    }
    cin >> p >> k;
    for(int i = 0;i < p;i++){
        for(int j = 0;j < k;j++){
            int a, b;
            cin >> a >> b;
            ret[a].push_back({b, i});
            ret[b].push_back({a, i});
        }
        
    }
    for(int i = 0;i < p;i++){
        for(int j = 0;j < k;j++){
            check();
        }
    }

    return 0;
}

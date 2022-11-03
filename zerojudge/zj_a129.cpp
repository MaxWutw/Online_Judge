// MST
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int p[100005];
struct Edge{
    int u, v, w;
};
bool cmp(Edge e1, Edge e2){
    return e1.w < e2.w;
}
int query(int x){
    if(p[x] < 0) return x;
    return p[x] = query(p[x]);
}
bool joint(int u, int v){
    int r1 = query(u), r2 = query(v);
    if(r1 == r2) return false;
    if(r1 < r2) p[r2] = r1;
    else p[r1] = r2;
    return true;
}
int main(){
    IOS
    int n, m;
    while(cin >> n >> m){
        vector<Edge> edge;
        memset(p, -1, sizeof(p));
        for(int i = 0;i < m;i++){
            int a, b, c;
            cin >> a >> b >> c;
            edge.push_back({a, b, c});
        }
        ll cost = 0, cnt = 0;
        sort(edge.begin(), edge.end(), cmp);
        for(Edge e : edge){
            if(joint(e.u, e.v)){
                cost += e.w;
                cnt++;
            }
        }
        if(cnt < n - 1) cout << -1 << '\n';
        else cout << cost << '\n';
    }
    return 0;
}
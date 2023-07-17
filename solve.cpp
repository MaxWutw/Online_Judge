#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;
int t;
ll dsu[(2 * N) + 5];
int sz[N + 5];
int Find(int x){
    if(dsu[x] != x) dsu[x] = Find(dsu[x]);
    return dsu[x];
}
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(sz[x] < sz[y]) swap(x, y);
    dsu[y] = x;
    sz[x] += sz[y];
}
int main(){
    IOS
    cin >> t;
    while(t--){
        memset(sz, 0, sizeof(sz));
        int n, m;
        cin >> n >> m;
        for(int i = 0;i < m;i++){
            int a, b;
            string c;
            cin >> a >> b >> c;
            Union()
        }
    }

    return 0;
}

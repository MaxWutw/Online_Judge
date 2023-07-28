// dsu
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int t;
ll dsu[(2 * N) + 5], sz[(2 * n) + 5], w[(2 * n) + 5];
ll Find(int x){
    if(x == dsu[x]) return dsu[x];
    dsu[x] = Find(dsu[x]);
}
void Union(int a, int b){
    a = Find(a), b = Find(b);
    if(a != b){
        if(sz[a] < sz[b]) swap(a, b);
        dsu[b] = a;
        sz[a] += sz[b];
    }
}
int main(){
    IOS
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 1;i <= n;i++) w[i] = 1, dsu[i] = i;
        for(int i = n + 1;i <= (2 * n);i++) w[i] = 0, dsu[i + n] = i + n;
        for(int i = 0;i < m;i++){
            int a, b;
            string str;
            cin >> a >> b >> str;
            if(str[0] == 'c'){
                Union(a, b);
                Union(a + n, b + n);
            }
            else{
                Union(a, b + n);
                Union(a + n, b);
            }
        }
        ll res = 0;
        for(int i = 1;i <= n;i++){
            if(Find(i) == Find(i + n)){
                cout << -1 << '\n';
                return;
            }
            
        }
    }

    return 0;
}

// disjoint set union-find algorithm
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int p[10005];
int find(int x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}
int main(){
    IOS
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0;i < n;i++) p[i] = i;
    int a, b;
    for(int i = 0;i < m;i++){
        cin >> a >> b;
        a--;b--;
        p[find(a)] = find(b);
    }
    for(int i = 0;i < q;i++){
        cin >> a >> b;
        if(find(a-1) == find(b-1)) cout << ":)\n";
        else cout << ":(\n";
    }
    
    return 0;
}
// disjoint set union-find algorithm
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int p[1000005];
int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
int main(){
    IOS
    int n, m;
    while(cin >> n >> m){
        for(int i = 0;i < n + 5;i++) p[i] = -1;
        int a, b;
        int mx = 1;
        for(int i = 0;i < m;i++){
            cin >> a >> b;
            a = find(a);
            b = find(b);
            if(a != b){
                p[a] += p[b];
                mx = max(mx, -p[a]);
                p[b] = a;
            }
        }
        cout << mx << '\n';
    }

    return 0;
}
// bitset
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll; 
int main(){
    IOS
    int n, x;
    cin >> n >> x;
    bitset<10005> vis[105];
    vis[0][0] = 1;
    for(int i = 1;i <= n;i++){
        int a, b;
        cin >> a >> b;
        vis[i] = vis[i - 1] << a | vis[i - 1] << b;
    }
    cout << (vis[n][x] ? "Yes" : "No") << '\n';

    return 0;
}
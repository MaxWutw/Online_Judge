#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll n, m, arr[25][25], x, y;
unordered_map<ll> m[25][25];
void dfs(int a, int b, ll val){
    if(a > x || b > y) return;
    if(a + b == (n + m - 1) >> 1){

    }
    dfs(a + 1, b, val ^ arr[a + 1][b]);
    dfs(a, b + 1, val ^ arr[a][b + 1]);
}
int main(){
    IOS
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> arr[i][j];
        }
    }
    dfs(0, 0);

    return 0;
}
// Meet in the middle
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll n, m, arr[25][25], ans = 0, k;
map<ll, ll> ma[25][25];
void dfs(int a, int b, ll val){
    if(a >= n || b >= m) return;
    if(a + b == (n + m - 1) / 2){
        ma[a][b][val ^ arr[a][b]]++;
        return;
    }
    dfs(a + 1, b, val ^ arr[a][b]);
    dfs(a, b + 1, val ^ arr[a][b]);
}
void dfs2(int a, int b, ll val){
    if(a < 0 || b < 0) return;
    if(a + b == (n + m - 1) / 2){
        ans += ma[a][b][val ^ k];
        return;
    }
    dfs2(a - 1, b, val ^ arr[a][b]);
    dfs2(a, b - 1, val ^ arr[a][b]);
}
int main(){
    IOS
    cin >> n >> m >> k;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> arr[i][j];
        }
    }
    dfs(0, 0, 0);
    dfs2(n - 1, m - 1, 0);
    cout << ans << '\n';

    return 0;
}
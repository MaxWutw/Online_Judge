#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n, m, k, x, y;
int arr[25][25];
unordered_map<ll, ll> m[25];
void dfs1(int c1, int c2){
    if(c1 > x || c2 > y) return;
    if(c1 == x && c2 == y){

    }
    dfs1(c1 + 1, c2);
    dfs(c1, c2 + 1);
}
int main(){
    IOS
    cin >> n >> m >> k;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> arr[i][j];
        }
    }
    x = n / 2, y = m / 2;
    dfs1(0);

    return 0;
}
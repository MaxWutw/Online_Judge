// 位元枚舉
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n;
ll arr[25], ans = 1e18;
int main(){
    IOS
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    for(int i = 0;i < (1 << (n - 1));i++){
        ll orn = 0, xorn = 0;
        for(int j = 0;j <= n;j++){
            if(j < n) orn |= arr[j];
            if(j == n || (i >> j & 1)){
                xorn ^= orn;
                orn = 0;
            }
        }
        ans = min(ans, xorn);
    }
    cout << ans << '\n';

    return 0;
}
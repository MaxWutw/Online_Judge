#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int mod = 10009;
ll arr[20], ans = 0, n;
void rec(int num, int cnt){
    if(cnt >= n){
        if(num == 1) ans++;
        return;
    }
    rec((num * arr[cnt]) % mod, ++cnt);
    rec(num, ++cnt);
}
int main(){
    IOS
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    rec(1, 0);
    cout << ans << '\n';

    return 0;
}
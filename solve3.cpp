#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        int tmp = 1, cnt = 0;
        while(tmp < l){
            tmp *= 3;
            cnt++;
        }
        tmp = l;
        int idx = 1, ans = 1;
        while(tmp <= r){
            if((tmp * 3) - 1 > r){
                ans += (r - tmp) * cnt;
            }
            else{
                ans += ((tmp * 3) - tmp) * cnt;
            }
            tmp *= 3;
            cnt += idx;
            idx++;
        }
        cout << ans + 1 << '\n';
    }

    return 0;
}
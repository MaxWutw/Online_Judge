// recursion
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll ans = 1e18, total = 0, arr[25];
int n;
ll div(int idx, ll sum){
    if(idx == n - 1) return abs(total - sum - sum);
    return min(div(idx + 1, arr[idx] + sum), div(idx + 1, sum));
}
int main(){
    IOS
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        total += arr[i];
    }
    cout << div(0, 0LL) << '\n';

    return 0;
}

// 位元枚舉
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n;
ll ans = 1e18, total = 0, arr[25];
int main(){
    IOS
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        total += arr[i];
    }
    for(int i = 0;i < (1 << n);i++){
        ll idx = 0, num = i, sum = 0;
        while(num != 0){
            if(num & 1) sum += arr[idx];
            num >>= 1;
            idx++;
        }
        ans = min(ans, abs(total - sum - sum));
    }
    cout << ans << '\n';

    return 0;
}
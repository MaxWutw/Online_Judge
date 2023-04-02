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
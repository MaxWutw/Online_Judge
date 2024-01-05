// b pointer
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int m, n, k;
ll a[100005], b[100005];
int main(){
    IOS
    cin >> m >> n >> k;
    for(int i = 0;i < m;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];
    sort(a, a + m);
    sort(b, b + n);
    int ans = 0, j = n - 1;
    for(int i = 0;i < m;i++){
        while(j > 0 && b[j] > k - a[i]) j--;
        if(a[i] + b[j] == k) ans++;
    }
    cout << ans << '\n';

    return 0;
}
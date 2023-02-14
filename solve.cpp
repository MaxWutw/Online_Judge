#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int arr[200005];
int main(){
    IOS
    int n;
    cin >> n;
    arr[0] = INF;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    stack<int> s;
    s.push(0);
    ll ans = 0;
    for(int i = 1;i <= n;i++){
        while(arr[s.top()] <= arr[i]) s.pop();
        ans += (i - s.top());
        s.push(i);
    }
    cout << ans << '\n';

    return 0;
}
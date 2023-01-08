// recursion

// version 1, linear search: line 14
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll n, L, arr[50005];
ll call(ll l, ll r){
    if(r - l <= 1) return 0;
    double mid = (arr[l] + arr[r]) >> 1;
    ll leng = arr[r] - arr[l];
    ll idx = l;
    while(arr[idx] < mid) idx++;
    if(arr[idx - 1] - arr[l] >= arr[r] - arr[idx]) idx--;
    return leng + call(l, idx) + call(idx, r);
}
int main(){
    IOS
    cin >> n >> L;
    arr[0] = 0, arr[n + 1] = L;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    ll ans = call(0, n + 1);
    cout << ans << '\n';


    return 0;
}

// version 2, 跳躍二分搜
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll n, L, arr[50005];
ll call(ll l, ll r){
    if(r - l <= 1) return 0;
    double mid = (arr[l] + arr[r]) >> 1;
    ll leng = arr[r] - arr[l];
    ll idx = l;
    for(int jump = (r - l) >> 1;jump > 0;jump >>= 1){
        while(idx + jump < r && arr[idx + jump] < mid) idx += jump;
    }
    if(arr[idx] - arr[l] < arr[r] - arr[idx + 1]) idx++;
    return leng + call(l, idx) + call(idx, r);
}
int main(){
    IOS
    cin >> n >> L;
    arr[0] = 0, arr[n + 1] = L;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    ll ans = call(0, n + 1);
    cout << ans << '\n';
    

    return 0;
}
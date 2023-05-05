// O(nlogn) by divide and conquer
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int n, arr[200005];
ll ans = 0;
ll divide(int l, int r){
    if(l >= r) return arr[l];
    // if(l + 1 == r) return max(arr[l], (ll)0);
    if(l + 1 == r) return arr[l];
    int mid = (l + r) >> 1;
    ll seq = max(divide(l, mid), divide(mid, r));
    ll left = arr[mid - 1], right = arr[mid], cursum = 0;
    for(int i = mid - 1;i >= l;i--){
        cursum += arr[i];
        left = max(left, cursum);
    }
    cursum = 0;
    for(int i = mid;i < r;i++){
        cursum += arr[i];
        right = max(right, cursum);
    }
    return max(seq, (left + right));
}
int main(){
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    ans = divide(0, n);
    cout << ans << '\n';

    return 0;
}

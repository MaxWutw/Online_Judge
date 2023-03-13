// divide and conquer O(nlogn)
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll subarr(ll arr[], int l, int r){
    if(l == r) return max(arr[l], (ll)0);
    int mid = (l + r) >> 1;
    ll maximum = max(subarr(arr, l, mid), subarr(arr, mid + 1, r));
    ll lsum = 0, rsum = 0, lmax = 0, rmax = 0;
    for(int i = mid;i >= l;i--){
        lsum += arr[i];
        lmax = max(lsum, lmax);
    } 
    for(int i = mid + 1;i <= r;i++){
        rsum += arr[i];
        rmax = max(rsum, rmax);
    }
    return max(maximum, lmax + rmax);
}
int main(){
    IOS
    ll n, arr[100005];
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    ll max_arr = subarr(arr, 0, n - 1);
    cout << max_arr << '\n';

    return 0;
}
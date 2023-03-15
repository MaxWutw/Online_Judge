// version 1: DaC O(nlog^2n)
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll inverse(int arr[], int l, int r){
    int mid = (l + r) >> 1;
    if(l + 1 >= r) return 0;
    ll mono = inverse(arr, l, mid) + inverse(arr, mid, r), cross = 0;
    sort(arr + mid, arr + r);
    for(int i = l;i < mid;i++){
        cross += lower_bound(arr + mid, arr + r, arr[i]) - (arr + mid);
    }
    return cross + mono;
}
int main(){
    IOS
    int n, arr[100005];
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    cout << inverse(arr, 0, n) << '\n';
    
    return 0;
}
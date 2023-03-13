#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll inverse(int arr[], int l, int r){
    if(l + 1 >= r) return 0;
    int mid = (l + r) >> 1;
    ll w = inverse(arr, l, mid) + inverse(arr, mid, r), cross = 0;
    ll tmp[r - l], j = mid, idx = 0;
    for(int i = l;i < mid;i++){
        while(j < r && arr[j] < arr[i]) tmp[idx++] = arr[j++];
        tmp[idx++] = arr[i];
        cross += (j - mid);
    }
    for(int i = l;i < j;i++) arr[i] = tmp[i - l];
    return w + cross;
}
int main(){
    IOS
    int n, arr[100005];
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    cout << inverse(arr, 0, n) << '\n';

    return 0;
}
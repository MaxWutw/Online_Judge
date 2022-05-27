// merge sort, D & C
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll n, arr[2000100], tmp[2000100], c = 1, cnt = 0;
void merge_(int left, int right){
    int mid = (left + right) >> 1;
    for(int i = left, j = mid + 1, k = left;k <= right;k++){
        if(i > mid) tmp[k] = arr[j++];
        else if(j > right) tmp[k] = arr[i++];
        else if(arr[i] <= arr[j]) tmp[k] = arr[i++];
        else{
            // cnt++;
            cnt += (mid - i + 1);
            tmp[k] = arr[j++];
        }
    }
    for(int i = left;i <= right;i++) arr[i] = tmp[i];
}
void merge_sort(int left, int right){
    if(left == right) return;
    int mid = (left + right) >> 1;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    merge_(left, right);
}
int main(){
    IOS
    while(cin >> n && n){
        cnt = 0;
        for(int i = 0;i < n;i++)
            cin >> arr[i];
        merge_sort(0, n - 1);
        cout << "Case #" << c++ << ": " << cnt << '\n';
    }

    return 0;
}
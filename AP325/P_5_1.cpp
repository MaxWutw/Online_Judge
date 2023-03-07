// divide and conquer method
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
pair<int, int> f(int arr[], int l, int r){
    if(l + 1 == r) return {arr[l], arr[l]};
    int m = (l + r) >> 1;
    pair<int, int> li = f(arr, l, m), ra = f(arr, m, r);
    return {min(li.first, ra.first), max(li.second, ra.second)};
}
int main(){
    IOS
    int n;
    cin >> n;
    int arr[100005];
    for(int i = 0;i < n;i++) cin >> arr[i];
    pair<int, int> out = f(arr, 0, n);
    cout << out.first << ' ' << out.second;

    return 0;
}
// 5   
// 47 21 8 96 52 15
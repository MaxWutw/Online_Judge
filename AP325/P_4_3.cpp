#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n, arr[100005];
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    sort(arr, arr + n);
    ll prefix[100005];
    prefix[0] = arr[0];
    for(int i = 1;i < n;i++){
        prefix[i] = arr[i] + prefix[i - 1];
    }
    ll total = 0;
    for(int i = 0;i < n;i++){
        total += prefix[i];
    }
    cout << total << '\n';

    return 0;
}
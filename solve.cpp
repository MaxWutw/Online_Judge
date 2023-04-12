#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    ll n, x;
    pair<ll, ll> arr[5005];
    cin >> n >> x;
    for(int i = 0;i < n;i++){

    }
    sort(arr, arr + n);
    int i = 0, j = n - 1;
    bool judge = false;
    while(i < j){
        int pos = lower_bound(arr + i, arr + j, x - arr[i] - arr[j]) - arr;
        if(arr[i] + arr[j] )
        if(pos == j + 1) judge = true;
    }
    if(judge) cout << "IMPOSSIBLE" << '\n';

    return 0;
}
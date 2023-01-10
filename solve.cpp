#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INf 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n, q, arr[100005], dif[100005];
int main(){
    IOS
    cin >> n >> q;
    for(int i = 0;i < n;i++) cin >> arr[i];
    dif[0] = arr[0];
    for(int i = 1;i < n;i++){
        dif[i] = arr[i] - arr[i - 1];
    }
    while(q--){
        int l, r, v;
        cin >> l >> r >> v;
        dif[l] += v;
        dif[r + 1] -= v;
    }

    return 0;
}
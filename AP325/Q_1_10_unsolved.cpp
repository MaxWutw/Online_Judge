// N queens, unsolved
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int n, arr[20], pos[20];
ll ans = -2147483647;
int queen(int k){
    if(k >= n) return 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < k;j++){
            if(pos[j] == i || )
        }
    }
}
int main(){
    IOS
    memset(pos, 0, sizeof(pos));
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    queen(n);
    cout << ans << '\n';

    return 0;
}
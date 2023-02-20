// two pointer
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll arr[200005];
int main(){
    IOS
    int n, k;
    cin >> n >> k;
    for(int i = 0;i < n;i++) cin >> arr[i];
    ll best = 0, total = 0, cur = 0;
    for(int l = 0, r = 0;r < n;r++){
        cur += arr[r];
        while(cur > k){
            cur -= arr[l];
            l++;
        }
        if(cur > best){
            best = cur;
            total = 1;
        }
        else if(cur == best) total++;
    }
    cout << best << '\n' << total << '\n';

    return 0;
}
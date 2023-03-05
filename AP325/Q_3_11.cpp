// sweep line
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int arr[200005], cnt[200005];
int main(){
    IOS
    int n;
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    int l = 0, r = 0, best = 0, cur = 0;
    while(r < n){
        cnt[arr[r]]++;;
        while(cnt[arr[r]] > 1){
            cnt[arr[l]]--;
            l++;
        }
        best = max(best, r - l);
        r++;
    }
    cout << best + 1 << '\n';

    return 0;
}
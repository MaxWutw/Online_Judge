#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
vector<ll> board(200005), post(5005);
int n, k;
int main(){
    IOS
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> board[i];
    for(int i = 1;i <= k;i++) cin >> post[i];
    int l = 1, r = 1000000001;
    while(l < r - 1){
        int mid = (l + r) >> 1;
        int cnt = 0, cur = 1;
        bool judge = false;
        for(int i = 1;i <= n;i++){
            if(board[i] >= mid){
                cnt++;
                if(cnt == post[cur]){
                    cnt = 0;
                    if(cur == k){
                        judge = true;
                        break;
                    }
                    cur++;
                }
            }
            else cnt = 0;
        }
        if(judge) l = mid;
        else r = mid;
    }
    cout << l << '\n';

    return 0;
}
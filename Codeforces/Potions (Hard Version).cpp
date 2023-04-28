// greedy + prirotiy queue
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll arr[200005];
int main(){
    IOS
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    int ans = 0;
    ll cur = 0;
    for(int i = 0;i < n;i++){
        if(arr[i] > 0){
            cur += arr[i];
            // cout << cur << '\n';
            ans++;
        }
        else if(cur + arr[i] >= 0){
            ans++;
            cur += arr[i];
            pq.push(arr[i]);
        }
        else{
            if(!pq.empty() && pq.top() < arr[i]){
                cur -= pq.top();
                pq.pop();
                cur += arr[i];
                pq.push(arr[i]);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}

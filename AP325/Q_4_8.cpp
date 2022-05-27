#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    ll arr[200005];
    int n, m; // 199487 48360
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> arr[i];
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    for(int i = 0;i < n;i++){
        if(pq.size() < m){
            pq.push(arr[i]);
        }
        else{
            ll tmp = pq.top() + arr[i];
            pq.pop();
            pq.push(tmp);
        }
    }
    for(int i = 0;i < m-1;i++) pq.pop();
    cout << pq.top() << '\n';
 
    return 0;
}
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll n, d, t[100005];
bool judge(int cnt){
    priority_queue<ll, vector<ll>, greater<ll> >  pq;
    for(int i = 0;i < n;i++){
        if(pq.size() < cnt) pq.push(t[i]);
        else{
            ll tmp = pq.top() + t[i];
            pq.pop();
            pq.push(tmp);
        }
    }
    for(int i = 0;i < cnt - 1;i++) pq.pop();
    return (pq.top() <= d ? true : false);
}
int main(){
    IOS
    cin >> n >> d;
    for(int i = 0;i < n;i++) cin >> t[i];
    int counter = n;
    for(int jump = n / 2;jump > 0;jump >>= 1){
        while(counter - jump > 0 && judge(counter - jump)){
            counter -= jump;
        }
    }
    cout << counter << '\n';

    return 0;
}
// unsolved
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll n, D, t[100005];
priority_queue<ll, vector<ll>, greater<ll> > pq;
bool judge(int i){
    int tmp = pq.top();
    pq.pop();
    if((tmp + t[i] > D && pq.empty()) || (i < n-1 && pq.top() + t[i] + t[i + 1] > D)){
        pq.push(tmp);
        return false;
    }
    // else if(tmp + t[i] > D && !pq.empty() && i < n && pq.top() + t[i] + t[i + 1] > D){
    //     pq.push(tmp);
    //     return false;
    // }
    else{
        pq.push(tmp);
        return true;
    }
}
int main(){
    IOS
    cin >> n >> D;
    for(int i = 0;i < n;i++) cin >> t[i];
    pq.push(t[0]);
    for(int i = 1;i < n;i++){
        if(!judge(i)){
            pq.push(t[i]);
        }
        else{
            ll tmp = pq.top();
            pq.pop();
            pq.push(tmp + t[i]);
        }
    }
    cout << pq.size() << '\n';
    while(!pq.empty()){
        cout << pq.top() << ' ';
        pq.pop();
    }

    return 0;
}
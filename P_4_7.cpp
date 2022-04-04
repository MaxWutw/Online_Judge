#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    priority_queue<ll> pq;
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        ll tmp;
        cin >> tmp;
        pq.push(-(ll)tmp);
    }
    ll total = 0;
    for(int i = 0;i < n-1;i++){
        ll x = pq.top();
        pq.pop();
        x += pq.top();
        pq.pop();
        pq.push(x);
        total += x;
    }
    cout << -pq.top() << '\n' << -total << '\n';

    return 0;
}
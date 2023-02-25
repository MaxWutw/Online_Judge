#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
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
        pq.push(-tmp);
    }
    ll total = 0;
    for(int i = 0;i < n - 1;i++){
        int tmp = pq.top();
        pq.pop();
        tmp += pq.top();
        pq.pop();
        pq.push(tmp);
        total += tmp;
    }
    cout << -pq.top() << '\n' << -total << '\n';

    return 0;
}
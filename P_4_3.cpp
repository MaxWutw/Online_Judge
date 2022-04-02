#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    IOS
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0;i < n;i++){
        int tmp;cin >> tmp;
        pq.push(tmp);
    }
    int prefix_sum[100005] = {0};
    prefix_sum[0] = pq.top();
    pq.pop();
    for(int i = 1;i < n;i++){
        prefix_sum[i] = prefix_sum[i - 1] + pq.top();
        pq.pop();
    }
    int total = 0;
    for(int i  = 0;i < n;i++){
        // cout << prefix_sum[i] << ' ';
        total += prefix_sum[i];
    }
    cout << total << '\n';

    return 0;
}
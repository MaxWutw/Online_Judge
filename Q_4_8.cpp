#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    IOS
    int n, m;
    priority_queue<pair<int, int>> pq;
    priority_queue<int> counter[200005];
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        int tmp;
        cin >> tmp;
        pq.push(make_pair(-i, tmp));
    }
    for(int i = 0;i < n;i++){
        pair<int, int> timing = pq.top();
        pq.pop();
        
    }

    return 0;
}
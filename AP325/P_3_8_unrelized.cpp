#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int arr[200005];
deque<int> max_q, min_q;
void put_max(int idx){
    while(!max_q.empty() && arr[max_q.back()] <= arr[idx])
        max_q.pop_back();
    max_q.push_back(idx);
}
void put_min(int idx){
    while(!min_q.empty() && arr[min_q.back()] >= arr[idx])
        min_q.pop_back();
    min_q.push_back(idx);
}
int main(){
    IOS
    int n, l, max_dif = 0;
    cin >> n >> l;
    for(int i = 0;i < n;i++) cin >> arr[i];
    put_max(0);
    put_min(0);
    for(int i = 0;i < n;i++){
        if(max_q.front() <= i - l) max_q.pop_front();
        put_max(i);
        if(min_q.front() <= i - l) min_q.pop_front();
        put_min(i);
        max_dif = max(max_dif, arr[max_q.front()] - arr[min_q.front()]);
    }
    cout << max_dif << '\n';

    return 0;
}
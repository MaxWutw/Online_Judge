// greedy + deque
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
pair<ll, ll> arr[100005];
int main(){
    IOS
    int n;
    pair<ll, ll> arr[100005];
    deque<ll> dq;
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n, [&](pair<ll, ll> a, pair<ll, ll> b){return a.second > b.second;});
    for(int i = 0;i < n;i++)
        dq.push_front(i);
    ll cnt = 0, ans = 0;
    while(!dq.empty()){
        if(!dq.empty() && arr[dq.front()].first <= 0) dq.pop_front();
        if(!dq.empty() && arr[dq.back()].first <= 0) dq.pop_back();
        if(dq.empty()) break;
        if(cnt >= arr[dq.front()].second){
            ans += arr[dq.front()].first;
            cnt += arr[dq.front()].first;
            dq.pop_front();
        }
        else{
            if(arr[dq.back()].first + cnt >= arr[dq.front()].second){
                arr[dq.back()].first -= (arr[dq.front()].second - cnt);
                ans += (2 * (arr[dq.front()].second - cnt));
                cnt += (arr[dq.front()].second - cnt);
            } 
            else{
                ans += (2 * arr[dq.back()].first);
                cnt += arr[dq.back()].first;
                dq.pop_back();
            }
        }
    }
    cout << ans << '\n';

    return 0;
}

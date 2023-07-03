// Monotonic Queue
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int arr[1000005];
int main(){
    IOS
    int n, k;
    while(cin >> n >> k){
        if(k > n) k = n;
        for(int i = 0;i < n;i++) cin >> arr[i];
        deque<int> dq;
        for(int i = 0;i < n;i++){
            while(dq.size() && dq.front() <= i - k) dq.pop_front();
            while(dq.size() && arr[dq.back()] > arr[i]) dq.pop_back();
            dq.push_back(i);
            if(i < k - 1) continue;
            if(i == n - 1) cout << arr[dq.front()];
            else cout << arr[dq.front()] << ' ';
        }
        cout << '\n';
        while(dq.size()) dq.pop_front();
        for(int i = 0;i < n;i++){
            while(dq.size() && dq.front() <= i - k) dq.pop_front();
            while(dq.size() && arr[dq.back()] < arr[i]) dq.pop_back();
            dq.push_back(i);
            if(i < k - 1) continue;
            if(i == n - 1) cout << arr[dq.front()];
            else cout << arr[dq.front()] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
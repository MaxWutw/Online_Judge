// merge sort, D & C
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll n, arr[2000100], tmp[2000100], c = 1, cnt = 0;
void merge_(int left, int right){
    int mid = (left + right) >> 1;
    for(int i = left, j = mid + 1, k = left;k <= right;k++){
        if(i > mid) tmp[k] = arr[j++];
        else if(j > right) tmp[k] = arr[i++];
        else if(arr[i] <= arr[j]) tmp[k] = arr[i++];
        else{
            // cnt++;
            cnt += (mid - i + 1);
            tmp[k] = arr[j++];
        }
    }
    for(int i = left;i <= right;i++) arr[i] = tmp[i];
}
void merge_sort(int left, int right){
    if(left == right) return;
    int mid = (left + right) >> 1;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    merge_(left, right);
}
int main(){
    IOS
    while(cin >> n && n){
        cnt = 0;
        for(int i = 0;i < n;i++)
            cin >> arr[i];
        merge_sort(0, n - 1);
        cout << "Case #" << c++ << ": " << cnt << '\n';
    }

    return 0;
}

// BIT

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
#define int long long
#define lowbit(x) x&(-x)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int N = 1e5 + 5;
int bit[N + 5];
int query(int idx){
    int ret = 0;
    for(int i = idx;i > 0;i-=lowbit(i)){
        ret += bit[i];
    }
    return ret;
}
void update(int idx){
    for(int i = idx;i <= N;i+=lowbit(i)){
        bit[i]++;
    }
}
signed main(){
    IOS
    int n, cnt = 1;
    while(cin >> n && n){
        int ans = 0, arr[N];
        memset(bit, 0, sizeof(bit));
        vector<int> b;
        for(int i = 0;i < n;i++) cin >> arr[i], b.push_back(arr[i]);
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        for(int i = 0;i < n;i++)
            arr[i] = lower_bound(b.begin(), b.end(), arr[i]) - b.begin() + 1;
        for(int i = 0;i < n;i++){
            ans += (i - query(arr[i]));
            update(arr[i]);
        }
        cout << "Case #" << cnt++ << ": " << ans << '\n';
    }

    return 0;
}

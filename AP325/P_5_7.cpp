// O(N ^ 2) TLE
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll; 
ll n, arr[100005];
ll dc(int l, int r){
    if(l >= r) return 0;
    if(l + 1 == r) return arr[l];
    int mini = min_element(arr + l, arr + r) - arr;
    ll max_n = arr[mini] * (r - l);
    max_n = max(max_n, dc(l, mini));
    max_n = max(max_n, dc(mini + 1, r));
    return max_n;
}
int main(){
    IOS
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    cout << dc(0, n) << '\n';

    return 0;
}

// O(NlgN)
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll n, arr[100005];
ll dc(int l, int r){
    if(l >= r) return 0;
    if(l + 1 == r) return arr[l];
    ll mid = (l + r) >> 1;
    ll maxh = max(dc(l, mid), dc(mid + 1, r));
    ll i = mid, j = mid, maximum = 0, height = arr[mid];
    while(i >= l || j < r){
        if(i < l) height = arr[j];
        else if(j >= r) height = arr[i];
        else height = max(arr[i], arr[j]);
        while(i >= l && arr[i] >= height) i--;
        while(j < r && arr[j] >= height) j++;
        maximum = max(maximum, (j - i - 1) * height);
    }
    return max(maximum, maxh);
}
int main(){
    IOS
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    cout << dc(0, n) << '\n';

    return 0;
}
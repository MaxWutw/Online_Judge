#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll n, pre[300005] = {0}, arr[300005];
bool cmp(int a, int b){
    return arr[a] > arr[b];
}
vector<ll> vec;
int main(){
    IOS
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        vec.push_back(i);
        pre[i] = pre[i - 1] + arr[i];
    }
    sort(vec.begin(), vec.end(), cmp);
    int l = 1, r = n;
    while(l != r){
        while(vec.back() < l || vec.back() > r) vec.pop_back();
        int m = vec.back();
        vec.pop_back();
        ll t1 = pre[m - 1] - pre[l - 1], t2 = pre[r] - pre[m];
        if(t1 > t2) r = m - 1;
        else l = m + 1;
    }
    cout << arr[l] << '\n';

    return 0;
}
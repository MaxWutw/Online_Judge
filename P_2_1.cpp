// sort
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 2147483647
using namespace std;
typedef long long ll;
ll n, arr[100005], des[100005];
int main(){
    IOS
    cin >> n;
    ll tmp;
    for(int i = 0;i < n;i++) cin >> arr[i];
    sort(arr, arr + n);
    des[0] = arr[0];
    int idx = 1;
    for(int i = 1;i < n;i++){
        if(arr[i - 1] != arr[i]){
            des[idx++] = arr[i];
        }
    }
    cout << idx << '\n';
    for(int i = 0;i < idx;i++) cout << des[i] << ' ';

    return 0;
}
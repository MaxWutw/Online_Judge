// b pointers, O(N ^ 2)
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n, x;
    pair<ll, ll> arr[5005];
    cin >> n >> x;
    for(int i = 0;i < n;i++){
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr, arr + n);
    for(int i = 0;i < n;i++){
        int l = 0, r = n - 1;
        while(l != r){
            if(l != i && r != i && (x - arr[i].first) == (arr[l].first + arr[r].first)){
                cout << arr[l].second << ' ' << arr[i].second << ' ' << arr[r].second << '\n';
                return 0;
            }
            if((x - arr[i].first) < (arr[l].first + arr[r].first)) r--;
            else l++;
        }
    }
    cout << "IMPOSSIBLE" << '\n';

    return 0;
}
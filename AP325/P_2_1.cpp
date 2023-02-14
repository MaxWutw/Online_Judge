// sort
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int n, arr[100005];
int add[100005];
int main(){
    IOS
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    sort(arr, arr + n);
    add[0] = arr[0];
    int ans = 1;
    for(int i = 1;i < n;i++){
        if(arr[i - 1] != arr[i]) add[ans++] = arr[i];
    }
    cout << ans << '\n';
    for(int i = 0;i < ans;i++) cout << add[i] << ' ';

    return 0;
}
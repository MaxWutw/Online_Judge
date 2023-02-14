// discretization + sort
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int n, arr[100005];
int main(){
    IOS
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    vector<int> cop(arr, arr + n);
    sort(cop.begin(), cop.end());;
    int add[200005];
    add[0] = cop[0];
    int cnt = 1;
    for(int i = 1;i < n;i++){
        if(cop[i - 1] != cop[i]) add[cnt++] = cop[i];
    }
    for(int i = 0;i < n;i++){
        arr[i] = lower_bound(add, add + cnt, arr[i]) - add;
    }
    for(int i = 0;i < n - 1;i++) cout << arr[i] << ' ';
    cout << arr[n - 1] << '\n';

    return 0;
}
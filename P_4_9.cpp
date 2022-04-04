// Binary search + greedy
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll n, k, arr[50005];
bool judge(int num){
    int base = k, range = -1;
    for(int i = 0;i < n;i++){
        if(arr[i] <= range) continue;
        if(base == 0) return false;
        base--;
        range = arr[i] + num;
    }
    return true;
}
int main(){
    IOS
    cin >> n >> k;
    for(int i = 0;i < n;i++) cin >> arr[i];
    sort(arr, arr + n);
    int length = 0, total = arr[n-1] - arr[0];
    for(int i = n/2;i > 0;i>>=1){
        while(length + i <= total && !judge(length+i)) length += i;
    }
    cout << length + 1 << '\n';

    return 0;
}
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    int arr[19] = {1, 3, 4};
    int idx = lower_bound(arr, arr + 3, 2) - arr;
    cout << idx << '\n';

    return 0;
}
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    IOS
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int it = lower_bound(arr, arr + 9, 100) - arr;
    cout << it << '\n';

    return 0;
}
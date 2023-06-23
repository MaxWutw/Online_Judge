#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
<<<<<<< HEAD
    int arr[19] = {1, 3, 4};
    int idx = lower_bound(arr, arr + 3, 2) - arr;
=======
    IOS
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int idx = upper_bound(vec.begin(), vec.end(), 11) - vec.begin();
>>>>>>> 556b975384d942657ca4680e256dad2599e5d6cc
    cout << idx << '\n';

    return 0;
}
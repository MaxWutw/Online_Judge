// Greedy, Maximum Subarray
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n;
    cin >> n;
    ll max_num = 0, prefix = 0;
    for(int i = 0;i < n;i++){
        ll num;
        cin >> num;
        prefix = (prefix > 0) ? num + prefix : num;
        max_num = max(max_num, prefix);
    }
    cout << max_num << '\n';

    return 0;
}
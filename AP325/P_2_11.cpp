#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n, k;
    cin >> n >> k;
    int best = 0, prefix = 0;
    set<int> s({0});
    for(int i = 0;i < n;i++){
        int inp;
        cin >> inp;
        prefix += inp;
        auto it = s.lower_bound(prefix - k);
        if(it != s.end()) best = max(best, prefix - *it);
        s.insert(prefix);
    }
    cout << best << '\n';

    return 0;
}
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);
using namespace std;
int main(){
    IOS
    pair<int, int> a[5], b[5];
    cin >> a[0].first >> a[0].second >> a[1].first >> a[1].second >> b[0].first >> b[0].second >> b[1].first >> b[1].second;
    int x, y;
    cin >> x >> y;
    int big_left = min(a[0].first, a[1].first), big_right = max(a[0].first, a[1].first), small_left = min(b[0].first, b[1].first), small_right = max(b[0].first, b[1].first);
    if(x > small_left && x < small_right) cout << 0;
    else if((x > big_left && x < small_left) || (x > small_right && x < big_right)) cout << 1;
    else cout << 2;

    return 0;
}
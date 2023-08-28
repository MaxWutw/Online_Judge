#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int vis[N];
int main(){
    IOS
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int p = lower_bound(arr.begin(), arr.end(), 3) - arr.begin();
    cout << p << '\n';

    return 0;
}

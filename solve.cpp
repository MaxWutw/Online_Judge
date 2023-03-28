#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n, cost;
    cin >> n;
    int p = 0, pp = 0;
    for(int i = 0;i < n;i++){
        cin >> cost;
        cost += min(p, pp);
        pp = p;
        p = cost;
    }
    cout << cost << '\n';

    return 0;
}
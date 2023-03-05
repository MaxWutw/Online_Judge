#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    tuple<int, int, int> t;
    t = {1, 2, 3};
    int a, b;
    tie(a, ignore, b) = t;
    cout << get<0>(t) << '\n';
    cout << b << '\n';

    return 0;
}
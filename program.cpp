#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int d;
int main(){
    IOS
    cin >> d;
    if(d > 0) cout << 2 * d - 1 << '\n';
    else if(d < 0) cout << (-2) * d << '\n';

    return 0;
}
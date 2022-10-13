// for loop 0.7s
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int d;
int main(){
    IOS
    cin >> d;
    int n, cnt = 0, day = 1;
    for(int i = 1;i <= 1000000000;i++){
        if(i & 1) cnt += i;
        else cnt -= i;
        if(cnt == d) break;
        day++;
    }
    cout << day << '\n';

    return 0;
}

// optimized, 2ms
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

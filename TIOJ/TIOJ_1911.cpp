// multiset
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
multiset<ll> ms;
int main(){
    IOS
    ll n;
    while(cin >> n && n){
        if(n > 0) ms.insert(n);
        else{
            if(ms.empty()) continue;
            if(n == -1){
                cout << *ms.begin() << ' ';
                ms.erase(ms.begin());
            }
            else{
                multiset<ll>::iterator iter = ms.end();
                iter--;
                cout << *iter << ' ';
                ms.erase(iter);
            }
        }
    }
    cout << '\n';

    return 0;
}

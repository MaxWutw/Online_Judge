// greedy
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    int m;
    cin >> m;
    int mon[5] = {50, 10, 5, 1};
    while(m--){
        int coin, total = 0;
        cin >> coin;
        for(int i = 0;i < 3 && coin > 0;i++){
            total += coin / mon[i];
            coin %= mon[i];
        }
        total += coin;
        cout << total << '\n';
    }

    return 0;
}
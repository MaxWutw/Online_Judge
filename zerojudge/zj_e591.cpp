// greedy
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int coin, pre = 0, cnt = 0, sum = 0;
        for(int i = 0;i < n;i++){
            cin >> coin;
            if(coin >= sum) sum = sum + coin - pre;
            else sum += coin;
        }
        cout << cnt << '\n';
    }

    return 0;
}
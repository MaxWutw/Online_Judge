// bitset
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll; 
int main(){
    IOS
    bitset<2505> friends[2505];
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        int d;
        cin >> d;
        int tmp;
        for(int j = 0;j < d;j++){
            cin >> tmp;
            friends[i][tmp] = true;
        }
    }
    int ans = 0;
    for(int i = 1;i < n;i++){
        for(int j = i + 1;j <= n;j++){
            ans += (friends[i] & friends[j]).any();
        }
    }
    cout << ans << '\n';

    return 0;
}
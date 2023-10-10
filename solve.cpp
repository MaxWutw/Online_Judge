#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
#define mod 998244353
#define int long long
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
signed main(){
    IOS
    int t;
    cin >> t;
    while(t--){
        int dp[N];
        string str;
        cin >> str;
        dp[1] = 
        for(int i = 1;i < str.size();i++){
            if(str[i - 1] != str[i + 1]){
                dp[i] = min(dp[i], );
            }
        }
    }

    return 0;
}
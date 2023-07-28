#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n, q;
int arr[N], dp[35][N];
int main(){
    IOS
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> arr[i], dp[0][i] = arr[i];
    for(int i = 1;i <= 31;i++){
        for(int j = 1;j <= n;j++){
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        int u = a;
        for(int i = 0;i <= 31;i++){
            if((1 << i) & b){
                u = dp[i][u];
            }
        }
        cout << u << '\n';
    }

    return 0;
}

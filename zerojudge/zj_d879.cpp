#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f3f3f
using namespace std;
typedef long long ll;
double x[20], y[20];
double dis(int i, int j){
    return sqrt(((x[i] - x[j]) * (x[i] - x[j])) + ((y[i] - y[j]) * (y[i] - y[j])));
}
int main(){
    IOS
    int n;
    int t = 0;
    while(cin >> n && n){
        n *= 2;
        cout << "Case " << ++t << ": ";
        double dp[(1 << 16) + 5];
        for(int i = 0;i < n;i++){
            string str;
            cin >> str >> x[i] >> y[i];
        }
        for(int i = 0;i < (1 << 16);i++) dp[i] = INF;
        dp[0] = 0;
        for(int s = 0;s < (1 << n);s++){
            for(int i = 0;i < n;i++){
                if(s & (1 << i)){
                    for(int j = i + 1;j < n;j++){
                        if(s & (1 << j)){
                            dp[s] = min(dp[s], dp[s ^ (1 << i) ^ (1 << j)] + dis(i, j));
                        }
                    }
                }
            }
        }
        cout << fixed << setprecision(2) << dp[(1 << n) - 1] << '\n';
    }

    return 0;
}
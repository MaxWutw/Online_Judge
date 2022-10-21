// Floyd-Warshall algorithm
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n, cnt = 1;
    while(cin >> n && n){
        vector<pair<double, double> > adj;
        double dp[205][205];
        for(int i = 0;i < n;i++){
            double x, y;
            cin >> x >> y;
            adj.push_back({x, y});
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                dp[i][j] = sqrt((adj[i].first - adj[j].first) * (adj[i].first - adj[j].first) + (adj[i].second - adj[j].second) * (adj[i].second - adj[j].second));
            }
        }
        for(int k = 0;k < n;k++){
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n;j++){
                    dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));
                }
            }
        }
        cout << "Scenario #" << cnt++ << '\n';
        cout << "Frog Distance = " << fixed << setprecision(3) << dp[0][1] << "\n\n";
    }

    return 0;
}

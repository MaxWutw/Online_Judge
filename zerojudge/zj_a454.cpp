// DAG dp, topological sort
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    int a;
    cin >> a;
    while(a--){
        int n;
        cin >> n;
        vector<vector<int> > adj(10005);
        int time[1005], indegree[1005], dp[1005];
        memset(indegree, 0, sizeof(indegree));
        memset(time, 0, sizeof(time));
        memset(dp, 0, sizeof(dp));
        queue<int> q;
        for(int i = 1;i <= n;i++){
            int t, k;
            cin >> t >> k;
            time[i] = t;
            for(int j = 0;j < k;j++){
                int num;
                cin >> num;
                adj[i].push_back(num);
                indegree[num]++;
            }
        }
        for(int i = 1;i <= n;i++)
            if(!indegree[i]) q.push(i);
        int total = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            dp[cur] += time[cur];
            total = max(total, dp[cur]);
            for(auto i : adj[cur]){
                dp[i] = max(dp[i], dp[cur]);
                indegree[i]--;
                if(!indegree[i]) q.push(i);
            }
        }
        cout << total << '\n';
    }

    return 0;
}

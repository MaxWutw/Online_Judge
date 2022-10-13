#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int c, s, q;
vector<vector<pair<int, int> > > vec(1005);
int dis[1005];
int main(){
    IOS
    int cnt = 1;
    while(cin >> c >> s >> q){
        if(c == 0 && s == 0 && q == 0) break;
        for(int k = 0;k < s;k++){
            int a, b, w;
            cin >> a >> b >> w;
            vec[a].push_back(make_pair(b, w));
            vec[b].push_back(make_pair(a, w));
        }
        // for(int i = 1;i <= c;i++){
        //     cout << i << ": ";
        //     for(auto i : vec[i]){
        //         cout << i.first << ' ';
        //     }
        //     cout << '\n';
        // }
        cout << "Case #" << cnt++ << '\n';
        while(q--){
            memset(dis, 0x3f3f3f3f, sizeof(dis));
            int c1, c2;
            cin >> c1 >> c2;
            priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
            dis[c1] = 0;
            pq.push(make_pair(0, c1));
            while(!pq.empty()){
                pair<int, int> cur = pq.top();
                if(cur.second == c2){
                    // cout << cur.second << '\n';
                    break;
                }
                if(dis[cur.second] < cur.first) continue;
                pq.pop();
                for(auto i: vec[cur.second]){
                    if(dis[i.first] > max(dis[cur.second], i.second)){
                        dis[i.first] = max(dis[cur.second], i.second);
                        // dis[i.first] = i.second + dis[cur.second];
                        pq.push(make_pair(dis[i.first], i.first));
                    }
                }
            }
            cout << (dis[c2] < 0x3f3f3f3f ? dis[c2] : 0) << '\n';
        }
    }

    return 0;
}

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
#define mod 998244353
#define int long long
using namespace std;
typedef long long ll;
int n, m, arr[1000][1000];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
signed main(){
    IOS
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        string str;
        cin >> str;
        for(int j = 0;j < m;j++){
            if(str[j] == '.') arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }
    queue<pair<int, int> > q;
    dq.push({0, 0});
    while(!q.empty()){
        auto cur = q.front();
        if(arr[cur.first][cur.second] == 1){
            for(int i = 0;i < 4;i++){
                if(cur.first + dx[i] >= 0 && cur.second + dy[i] >= 0 && cur.first + dx[i] < n && cur.second + dy[i] < m){
                    if(arr[cur.first + dx[i]][cur.second + dy[i]])
                }
            }
        }
    }

    return 0;
}
// bfs
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int arr[105][105], vis[105][105];
int dx[5] = {1, 0, 0, -1}, dy[5] = {0, 1, -1, 0};
int main(){
    IOS
    int s;
    int Case = 1;
    while(cin >> s){
        memset(arr, 0, sizeof(arr));
        memset(vis, 0, sizeof(vis));
        int n, m;
        cin >> n >> m;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                cin >> arr[i][j];
            }
        }
        int x, y;
        for(int i = 0;i < m;i++){
            if(arr[0][i] == 1){
                x = 0;
                y = i;
                break;
            }
        }
        queue<pair<int, int> > q;
        q.push({x, y});
        vis[x][y] = 1;
        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int i = 0;i < 5 - s;i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(arr[nx][ny] == 0) continue;
                if(vis[nx][ny] > 0) continue;
                q.push({nx, ny});
                vis[nx][ny] = vis[x][y] + 1;
            }
        }
        cout << "Case " << Case++ << ":\n";
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                cout << vis[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
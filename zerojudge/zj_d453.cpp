// BFS
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int dx[5] = {0, 1, 0, -1}, dy[5] = {1, 0, -1, 0};
int main(){
    IOS
    int n;
    cin >> n;
    while(n--){
        int n, m, sx, sy, ex, ey, p[105][105];
        int visited[105][105];
        cin >> n >> m >> sx >> sy >> ex >> ey;
        sx--;
        sy--;
        ex--;
        ey--;
        for(int i = 0;i < n;i++){
            string str;
            cin >> str;
            for(int j = 0;j < m;j++){
                p[i][j] = str[j] - '0';
            }
        }
        memset(visited, -1, sizeof(visited));
        queue<pair<int, int> > q;
        visited[sx][sy] = 1;
        q.push(make_pair(sx, sy));
        while(!q.empty()){
            pair<int, int> cur;
            cur = q.front();
            q.pop();
            for(int i = 0;i < 4;i++){
                if(cur.first + dx[i] >= 0 && cur.second + dy[i] >= 0 && cur.first + dx[i] < n && cur.second + dy[i] < m){
                    if(visited[cur.first + dx[i]][cur.second + dy[i]] == -1 && p[cur.first + dx[i]][cur.second + dy[i]] == 0){
                        q.push(make_pair(cur.first + dx[i], cur.second + dy[i]));
                        visited[cur.first + dx[i]][cur.second + dy[i]] = visited[cur.first][cur.second] + 1;
                    }
                }
            }
        }
        if(visited[ex][ey] == -1) cout << 0 << '\n';
        else cout << visited[ex][ey] << '\n';
    }

    return 0;
}
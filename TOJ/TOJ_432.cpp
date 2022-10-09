// bfs
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int n, m, sx, sy, f, ex, ey;
int area[1005][1005];
bool visited[1005][1005];
int dx[5] = {0, 1, 0, -1}, dy[5] = {1, 0, -1, 0};
bool bfs(int fx, int fy){
    queue<pair<int, int> > Q;
    Q.push(make_pair(fx, fy));
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        if(cur.first == ex && cur.second == ey) return true;
        for(int i = 0;i < 4;i++){
            if(cur.first + dx[i] > 0 && cur.first + dx[i] <= n && cur.second + dy[i] > 0 && cur.second + dy[i] <= m){
                if(visited[cur.first + dx[i]][cur.second + dy[i]] == 0 && area[cur.first + dx[i]][cur.second + dy[i]] != 1){
                    visited[cur.first + dx[i]][cur.second + dy[i]] = 1;
                    Q.push(make_pair(cur.first + dx[i], cur.second + dy[i]));
                }
            }
        }
    }

    return false;
}
int main(){
    IOS
    memset(visited, false, sizeof(visited));
    memset(area, 0, sizeof(area));
    cin >> n >> m;
    cin >> sx >> sy;
    cin >> ex >> ey;
    cin >> f;
    for(int i = 0;i < f;i++){
        int tmpx, tmpy;
        cin >> tmpx >> tmpy;
        area[tmpx][tmpy] = 1;
    }
    cout << (bfs(sx, sy) ? "Cool!\n" : "Harakiri!\n");

    return 0;
}

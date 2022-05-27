#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int dx[5] = {1, 0, -1, 0}, dy[5] = {0, 1, 0, -1};
int main(){
    IOS
    // freopen("sample1.in", "r", stdin);
    int n, m, area[1005][1005];
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0;i < m;i++){
            cin >> area[i][j];
        }
    }
    int ax, ay, bx, by;
    cin >> bx >> by >> ax >> ay;
    ax--;
    ay--;
    bx--;
    by--;
    queue<pair<int, int> > q;
    q.push(make_pair(bx, by));
    int visited[1005][1005];
    memset(visited, 0, sizeof(visited));
    visited[bx][by] = 1;
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for(int i = 0;i < 4;i++){
            if(cur.first + dx[i] >= 0 && cur.second + dy[i] >= 0 && cur.first + dx[i] < n && cur.second + dy[i] < m){
                if((abs(cur.first + dx[i] - ax) + abs(cur.second + dy[i] - ay)) <= 3){
                    cout << "yes" << '\n';
                    return 0;
                }
                else{
                    if(area[cur.first + dx[i]][cur.second + dy[i]] - area[cur.first][cur.second] == 1 && !visited[cur.first + dx[i]][cur.second + dy[i]]){
                        q.push(make_pair(cur.first + dx[i], cur.second + dy[i]));
                        visited[cur.first + dx[i]][cur.second + dy[i]] = 1;
                    }
                    else if(area[cur.first][cur.second] - area[cur.first + dx[i]][cur.second + dy[i]] >= 0 && area[cur.first][cur.second] - area[cur.first + dx[i]][cur.second + dy[i]] <= 2 && !visited[cur.first + dx[i]][cur.second + dy[i]]){
                        q.push(make_pair(cur.first + dx[i], cur.second + dy[i]));
                        visited[cur.first + dx[i]][cur.second + dy[i]] = 1;
                    }
                }
            }
        }
    }
    cout << "no" << '\n';

    return 0;
}
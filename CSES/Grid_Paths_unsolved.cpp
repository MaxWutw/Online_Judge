#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
char grid[10][10];
int ans = 0, vis[10][10];
int dx[5] = {0, -1, 0, 1}, dy[5] = {1, 0, -1, 0};
void dfs(int depth, int idx, int cnt){
    if(depth == 6 && idx == 0 && cnt == 48){
        ans++;
        return;
    }
    if(depth < 0 || depth > 6 || idx < 0 || idx > 6 || vis[depth][idx]){
        return;
    }
    if(grid[depth][idx] == 'D'){
        if(depth >= 6) return;
        if(vis[depth + 1][idx]) return;
        if(idx == 6 && depth > 0 && vis[depth - 1][idx] == 0) return;
        vis[depth][idx] = 1;
        dfs(depth + 1, idx, cnt + 1);
        vis[depth][idx] = 0;
    }
    else if(grid[depth][idx] == 'U'){
        if(depth <= 0) return;
        if(vis[depth - 1][idx]) return;
        if(idx == 6 && depth < 6 && vis[depth + 1][idx] == 0) return;
        vis[depth][idx] = 1;
        dfs(depth - 1, idx, cnt + 1);
        vis[depth][idx] = 0;
    }
    else if(grid[depth][idx] == 'L'){
        if(idx <= 0) return;
        if(vis[depth][idx - 1]) return;
        if(depth == 6 && idx < 6 && vis[depth][idx + 1] == 0) return;
        vis[depth][idx] = 1;
        dfs(depth, idx - 1, cnt + 1);
        vis[depth][idx] = 0;
    }
    else if(grid[depth][idx] == 'R'){
        if(idx >= 6) return;
        if(vis[depth][idx + 1]) return;
        if(depth == 6 && idx > 0 && vis[depth][idx - 1] == 0) return;
        vis[depth][idx] = 1;
        dfs(depth, idx + 1, cnt + 1);
        vis[depth][idx] = 0;
    }
    else if(grid[depth][idx] == '?'){
        for(int i = 0;i < 4;i++){
            vis[depth][idx] = 1;
            dfs(depth + dx[i], idx + dy[i], cnt + 1);
            vis[depth][idx] = 0;
        }
    }
}
int main(){
    IOS
    memset(vis, 0, sizeof(vis));
    string str;
    cin >> str;
    int idx = 0;
    grid[6][0] = 'E';
    for(int i = 0;i < 7;i++){
        for(int j = 0;j < 7;j++){
            if(i == 6 && j == 0) continue;
            grid[i][j] = str[idx++];
        }
    }
    // for(int i = 0;i < 7;i++){
    //     for(int j = 0;j < 7;j++){
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    dfs(0, 0, 0);
    cout << ans << '\n';

    return 0;
}
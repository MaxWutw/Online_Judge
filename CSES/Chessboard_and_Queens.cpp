#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
bool visited[10][10], maze[10][10];
int ans = 0;
bool valid(int x, int y){
    for(int i = 0;i < 8;i++){
        for(int j = 0;j < 8;j++){
            if(visited[i][j]){
                if(x == i || y == j) return false;
                if(abs(i - x) == abs(j - y)) return false;
            }
        }
    }
    return true;
}
void dfs(int depth){
    if(depth == 8){
        ans++;
        return;
    }
    for(int i = 0;i < 8;i++){
        if(valid(depth, i) && maze[depth][i]){
            visited[depth][i] = 1;
            dfs(depth + 1);
            visited[depth][i] = 0;
        }
    }
}
int main(){
    IOS
    memset(visited, 0, sizeof(visited));
    memset(maze, 0, sizeof(maze));
    for(int i = 0;i < 8;i++){
        string str;
        getline(cin, str);
        for(int j = 0;j < 8;j++){
            if(str[j] == '.') maze[i][j] = 1;
        }
    }
    dfs(0);
    cout << ans << '\n';

    return 0;
}
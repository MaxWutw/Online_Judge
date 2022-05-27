// dfs permutation from 1 to n
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);
using namespace std;
int n, res[362700] = {0}, visited[20] = {0};
void dfs(int depth){
    if(depth == n){
        cout << res[0];
        for(int i = 1;i < n;i++) cout << ' ' << res[i];
        cout << '\n';
        return;
    }
    for(int i = 1;i <= n;i++){
        if(visited[i]) continue;
        visited[i] = 1;
        res[depth] = i;
        dfs(depth + 1);
        visited[i] = 0;
    }
}
int main(){
    IOS
    cin >> n;
    dfs(0);

    return 0;
}
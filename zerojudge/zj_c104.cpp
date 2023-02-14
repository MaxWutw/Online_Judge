// dfs + puring and 8 queens
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int arr[10][10], m[10];
int ans = 0;
void dfs(int depth){
    if(depth >= 8){
        int sum = 0;
        for(int i = 0;i < 8;i++){
            sum += arr[i][m[i]];
        }
        ans = max(ans, sum);
        return;
    }
    for(int i = 0;i < 8;i++){
        for(int j = 0;j < depth;j++){
            if(m[j] == i || (abs(m[j] - i) == depth - j)) break;
            if(j == depth - 1){
                m[depth] = i;
                dfs(depth + 1);
            }
        }
    }
}
int main(){
    IOS
    int k;
    cin >> k;
    while(k--){
        ans = 0;
        for(int i = 0;i < 8;i++){
            for(int j = 0;j < 8;j++){
                cin >> arr[i][j];
            }
        }
        for(int i = 0;i < 8;i++){
            m[0] = i;
            dfs(1);
        }
        cout << setw(5) << ans << '\n';
    }
    
    return 0;
}
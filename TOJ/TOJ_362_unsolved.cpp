// unsolved
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int arr[20][20], top[10] = {0};
bool judge = false;
void dfs(int depth){
    
    for(int i = 0;i < 4;i++){
        for(int j = i + 1;j < 4;j++){
            if(top[i] < 13 && top[j] < 13 && arr[i][top[i]] == arr[j][top[j]]){
                top[i]++;
                top[j]++;
                dfs(depth + 1);
                top[i]--;
                top[j]--;
            }
        }
    }
}

int main(){
    IOS
    while(true){
        for(int i = 0;i < 4;i++){
            for(int j = 0;j < 13;j++){
                cin >> arr[i][j];
            }
        }
        dfs(0);
        cout << (judge ? "YES" : "NO") << '\n';
    }

    return 0;
}
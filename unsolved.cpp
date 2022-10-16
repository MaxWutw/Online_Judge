#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int n, total, arr[20];
bool visited[100];
int dfs(int depth){
    if(depth > n){
        total++;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                cout << 
            }
        }
    }
}
int main(){
    IOS
    
    while(cin >> n && n){
        for(int i = 0;i < n;i++) arr[i] = i;
        dfs(1);
    }

    return 0;
}

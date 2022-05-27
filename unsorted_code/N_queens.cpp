// N queens, dfs + purning
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int arr[20] = {0}, total = 0, n;
bool is_valid(int t){
    for(int i = 1;i < t;i++){
        if(t - i == abs(arr[t] - arr[i])) return false;
    }
    return true;
}
void dfs(int depth){
    if(depth > n){
        total++;
        return;
    }
    for(int i = depth;i <= n;i++){
        swap(arr[depth], arr[i]);
        if(is_valid(depth)) dfs(depth + 1);
        swap(arr[depth], arr[i]);
    }
}
int main(){
    IOS
    cin >> n;
    for(int i = 1;i <= n;i++) arr[i] = i;
    dfs(1);
    cout << total << '\n';

    return 0;
}
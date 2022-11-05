#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll arr[100005];
vector<int> vec;
ll ans = 0;
int dfs(int v){
    if(vec[v] == 0) return 0;
    for(int i = 0;i < 2 + ((vec[v] & 1)? 1 : 0);i++){
        int next = dfs(v++);
        ans += abs(vec[v] - vec[next]);
    }
    return v;
}
int main(){
    IOS
    int tmp;
    while(cin >> tmp) vec.push_back(tmp);
    dfs(0);
    cout << ans << '\n';

    return 0;
}
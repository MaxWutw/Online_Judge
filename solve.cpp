#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
vector<int> vec[200005];
int n, m;
bitset<200005> vis;
int color[200005];
int main(){
    IOS
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            
        }
    }

    return 0;
}

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int n, parent[100005], deg[100005], h[100005];
int main(){
    IOS
    queue<int> q;
    cin >> n;
    memset(deg, 0, sizeof(deg));
    memset(parent, 0, sizeof(parent));
    memset(h, 0, sizeof(h));
    for(int i = 1;i <= n;i++){
        cin >> deg[i];
        if(deg[i] == 0) q.push(i);
        for(int j = 0;j < deg[i];j++){
            int tmp;
            cin >> tmp;
            parent[tmp] = i;
        }
    }
    int total = 0, root;
    while(true){
        int v = q.front();
        q.pop();
        total += h[v];
        int p = parent[v];
        if(p == 0){
            root = v;
            break;
        }
        h[p] = max(h[p], h[v] + 1);
        if(--deg[p] == 0) q.push(p);
    }
    cout << root << '\n' << total << '\n';

    return 0;
}
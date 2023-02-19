// O(N)
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
struct Data{
    int c, h;
    int prev, next;
    bool alive;
};
queue<int> q;
Data tree[100005];
int total = 0, height = 0;
void remove(int idx){
    int pr = tree[idx].prev, ne = tree[idx].next;
    if(!tree[idx].alive) return;
    if(tree[idx].c - tree[idx].h >= tree[pr].c || tree[idx].c + tree[idx].h <= tree[ne].c){
        tree[pr].next = ne;
        tree[ne].prev = pr;
        tree[idx].alive = false;
        q.push(idx);
    }
    return;
}
int main(){
    IOS
    int n, l;
    cin >> n >> l;
    for(int i = 1;i <= n;i++) cin >> tree[i].c;
    for(int i = 1;i <= n;i++) cin >> tree[i].h;
    tree[0].c = 0, tree[n + 1].c = l;
    tree[0].h = INF, tree[n + 1].h = INF;
    for(int i = 1;i <= n;i++){
        tree[i].prev = i - 1;
        tree[i].next = i + 1;
        tree[i].alive = true;
    }
    for(int i = 1;i <= n;i++){
        remove(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        height = max(height, tree[cur].h);
        total++;
        remove(tree[cur].prev);
        remove(tree[cur].next);
    }
    cout << total << '\n' << height << '\n';

    return 0;
}
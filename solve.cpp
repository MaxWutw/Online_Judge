#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define lowbit(x) (x & -x)
using namespace std;
typedef long long ll;
int n, m, tmp, tree[100005];
void update(int x, int k){
    while(x <= n){
        tree[x] += k;
        x += lowbit(x);
    }
}
int query(int x){
    int res = 0;
    while(x){
        res += tree[x];
        x -= lowbit(x);
    }
    return res;
}
vector<ll> vec1, vec2;
int main(){
    IOS
    while(cin >> n){
        memset(tree, 0, sizeof(tree));
        vec1.clear();
        vec2.clear();
        for(int i = 1;i <= n;i++){
            cin >> tmp;
            vec1.push_back(tmp);
            vec2.push_back(tmp);
        }
        sort(vec2.begin(), vec2.end());
        for(int i = 1;i <= n;i++){
            vec1[i] = lower_bound(vec2.begin(), vec2.end(), vec1[i]) - vec2.begin() + 1;
        }
        // for(int i = 0;i < n;i++) cout << vec1[i] << ' ';
        for(int i = 1;i <= n;i++){
            update(vec1[i], 1);
            cout << i - query(vec1[i]) + 1 << '\n';
        }
    }
    

    return 0;
}

// BIT
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int n;
ll arr[500005];
ll c1[500005], c2[500005];
class BIT{
public:
    void update(int x, int k);
    ll query(int x);
    inline void range_update(int x, int y, int k){
        this->update(x, k), this->update(y + 1, -k);
    }
    inline ll range_query(int x, int y){
        return (this->query(y) - this->query(x - 1));
    }
private:
    inline int lowbit(int x) { return (x & -x); };
};
void BIT::update(int x, int k){
    ll i = x;
    while(x <= n){
        c1[x] += k;
        c2[x] += k * (i - 1);
        x += lowbit(x);
    }
}
ll BIT::query(int x){
    ll res = 0, i = x;
    while(x){
        res += c1[x]*i - c2[x];
        x -= lowbit(x);
    }
    return res;
}
int main(){
    IOS
    cin >> n;
    BIT bit;
    memset(arr, 0, sizeof(arr));
    memset(c1, 0, sizeof(c1));
    memset(c2, 0, sizeof(c2));
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        bit.update(i, arr[i] - arr[i - 1]);
    }
    int q;
    cin >> q;
    while(q--) {
        int v, x, y, k;
        cin >> v;
        if(v == 1){
            cin >> x >> y >> k;
            bit.range_update(x, y, k);
        } 
        else{
            cin >> x >> y;
            cout << bit.range_query(x, y) << '\n';
        }

    }

    return 0;
}

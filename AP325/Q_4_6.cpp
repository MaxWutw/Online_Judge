#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
struct item{
    ll w, f;
};
bool cmp(struct item a, struct item b){
    return a.w * b.f < b.w * a.f;
}

int main(){
    IOS
    int n;
    struct item data[100005];
    cin >> n;
    for(int i = 0;i < n;i++) cin >> data[i].w;
    for(int i = 0;i < n;i++) cin >> data[i].f;
    sort(data, data + n, cmp);
    ll total = 0, energy = data[0].w;
    for(int i = 1;i < n;i++){
        total += energy * data[i].f; 
        energy += data[i].w;
    }
    cout << total << '\n';

    return 0;
}
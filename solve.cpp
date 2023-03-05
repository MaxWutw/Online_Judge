#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
struct Data{
    int m, s, t;
};
bool cmp(Data &a, Data &b){
    return a.s < b.s;
}
int main(){
    IOS
    int n;
    Data tp[100005];
    cin >> n;
    for(int i = 0;i < n;i++) cin >> tp[i].m;
    for(int i = 0;i < n;i++) cin >> tp[i].s;
    for(int i = 0;i < n;i++) cin >> tp[i].t;
    sort(tp, tp + n, cmp);
    ll max_p = 0;
    Data last = tp[0];
    for(int i = 1;i < n;i++){
        if(last.t < tp[i].s) max_p = max(max_p, last.m);
        
    }
    cout << max_p << '\n';

    return 0;
}
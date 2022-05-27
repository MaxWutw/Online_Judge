// unsolved
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
struct Gang{
    int m, s, t;
}
bool cmp(Gang a, Gang b){
    return a.s < b.s;
}
int main(){
    IOS
    int n;
    Gang group[100005];
    for(int i = 0;i < n;i++) cin >> group[i].m;
    for(int i = 0;i < n;i++) cin >> group[i].s;
    for(int i = 0;i < n;i++) cin >> group[i].t;
    sort(group, group + n, cmp);
    ll max_p = -1;
    for(int i = 0;i < n;i++){
        int cnt = i + 1;
        while(group[cnt].s < group[i].s && group[cnt].t < group[i].t){

        }
    }

    return 0;
}
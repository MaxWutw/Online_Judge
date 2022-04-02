#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
struct work{
    long long t, w;
};

bool cmp(struct work a, struct work b){
    return a.t * b.w < b.t * a.w;
}

int main(){
    IOS
    struct work item[100005];
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> item[i].t;
    for(int i = 0;i < n;i++) cin >> item[i].w;
    sort(item, item+n, cmp);
    long long total = 0, timing = 0;
    for(int i = 0;i < n;i++){
        timing += item[i].t;
        total += (timing * item[i].w);
    }
    cout << total << '\n';

    return 0;
}
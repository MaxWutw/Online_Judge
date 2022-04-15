#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    return a.second < b.second;
}
int main(){
    IOS
    int n, t;
    cin >> t;
    while(t--){
        cin >> n;
        pair<ll, ll> task[100005];
        for(int i = 0;i < n;i++) cin >> task[i].first;
        for(int i = 0;i < n;i++) cin >> task[i].second;
        sort(task, task + n, cmp);
        ll timestep = 0;
        bool judge = true;
        for(int i = 0;i < n;i++){
            timestep += task[i].first;
            if(timestep > task[i].second){
                judge = false;
                break;
            }
        }
        if(judge) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}
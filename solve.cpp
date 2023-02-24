#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.first * b.second < a.second * b.first;
}
int main(){
    IOS
    int n;
    cin >> n;
    pair<int, int> job[100005];
    for(int i = 0;i < n;i++) cin >> job[i].first;
    for(int i = 0;i < n;i++) cin >> job[i].second;
    sort(job, job + n, cmp);
    ll penalty = 0, timestep = 0;
    for(int i = 0;i < n;i++){
        penalty += (job[i].first + timestep) * job[i].second;
        timestep += job[i].first;
    }
    cout << penalty << '\n';

    return 0;
}
// sweep line
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}
int main(){
    IOS
    pair<int, int> range[100005];
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> range[i].first >> range[i].second;
    sort(range, range + n, cmp);
    pair<int, int> last;
    last = range[0];
    long long total = 0;
    for(int i = 1;i < n;i++){
        if(range[i].first > last.second){
            total += (last.second - last.first);
            last = range[i];
        }
        else{
            if(range[i].second > last.second){
                last.second = range[i].second;
            }
        }
    }
    total += (last.second - last.first);
    cout << total << '\n';
    
    return 0;
}
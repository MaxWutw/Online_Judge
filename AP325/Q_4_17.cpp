#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.second < b.second;
}
int main(){
    IOS
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        pair<int, int> ass[100005];
        for(int i = 0;i < n;i++) cin >> ass[i].first;
        for(int i = 0;i < n;i++) cin >> ass[i].second;
        sort(ass, ass + n, cmp);
        int tp = 0;
        bool judge = true;
        for(int i = 0;i < n;i++){
            tp += ass[i].first;
            if(tp > ass[i].second) judge = false;
        }
        cout << (judge ? "yes" : "no") << '\n';
    }

    return 0;
}
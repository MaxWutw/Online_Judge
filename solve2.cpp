#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    int t;
    cin >> t;
    while(t--){
        int n, s, m;
        cin >> n >> s >> m;
        int pre = 0;
        bool judge = false;
        vector<pair<int, int> > vec(n);
        for(int i = 0;i < n;i++){
            int l, r;
            cin >> vec[i].first >> vec[i].second;
        }
        if(vec[0].first >= s){
            cout << "YES" << '\n';
            continue;
        }
        for(int i = 1;i < n;i++){
            if(vec[i].first - vec[i - 1].second >= s){
                judge = true;
                break;
            }
        }
        if(m - vec[n - 1].second >= s) judge = true;
        if(judge) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}
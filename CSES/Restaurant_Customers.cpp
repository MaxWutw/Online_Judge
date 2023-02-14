#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INf 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n;
int main(){
    IOS
    cin >> n;
    vector<pair<int, int> > vec;
    for(int i = 0;i < n;i++){
        int a, b;
        cin >> a >> b;
        vec.push_back({a, 1});
        vec.push_back({b, -1});
    }
    sort(vec.begin(), vec.end());
    int max_cus = -1, cur = 0;
    for(int i = 0;i < vec.size();i++){
        cur += vec[i].second;
        max_cus = max(max_cus, cur);
    }
    cout << max_cus << '\n';

    return 0;
}
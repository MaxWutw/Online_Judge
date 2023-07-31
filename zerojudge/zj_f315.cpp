#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int N = 2e5 + 5;
vector<int> v;
ll dc(vector<int> &vec, int l, int r){
    if(vec.size() <= 2) return 0;
    ll mid = (l + r) >> 1, dis = 0;
    vector<int> small, large;
    map<int, int> m;
    for(auto e : vec){
        if(e <= mid){
            dis += m.size();
            small.push_back(e);
        }
        else{
            large.push_back(e);
            if(m.count(e)) m.erase(e);
            else m[e] = 1;
        }
    }
    dis += dc(small, l, mid);
    dis += dc(large, mid + 1, r);
    return dis;
}
int main(){
    IOS
    int n;
    cin >> n;
    for(int i = 1;i <= 2 * n;i++){
        int tmp;
        cin >> tmp, v.push_back(tmp);
    }
    cout << dc(v, 1, 2 * n) << '\n';

    return 0;
}

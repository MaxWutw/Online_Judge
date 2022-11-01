#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll arr[200005];
vector<pair<int, int> > vec;
int main(){
    IOS
    int n, q;
    cin >> n >> q;
    for(int i = 0;i < n;i++) cin >> arr[i];
    for(int i = 0;i < q;i++){
        int l, r;
        cin >> l >> r;
        vec.push_back({l, r});
    }
    for(int i = 0;i < q;i++){
        
    }
    
    return 0;
}
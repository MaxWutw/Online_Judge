#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n, l;
    pair<int, int> loc[200005];
    cin >> n >> l;
    for(int i = 0;i < n;i++) cin >> loc[i].first >> loc[i].second;
    sort(loc, loc + n, [&](pair<int, int> a, pair<int, int> b){return a.second < b.second;});
    ll ans = 0;
    set<int> st;
    st.insert(0); st.insert(l);
    for(int i = 0;i < n;i++){
        set<int>::iterator left = st.upper_bound(loc[i].first), right = st.lower_bound(loc[i].first);
        if(*right == loc[i].first) right++;
        ans += (*right - *(--left));
        st.insert(loc[i].first);
    }
    cout << ans << '\n';

    return 0;
}
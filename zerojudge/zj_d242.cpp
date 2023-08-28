// LIS (NlogN)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
#define int long long
#define lowbit(x) x&(-x)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int N = 5e5 + 5;
vector<int> v, arr;
int dp[N];
signed main(){
    IOS
    int tmp;
    while(cin >> tmp)
        arr.push_back(tmp);
    for(int i = 0;i < arr.size();i++){
        int p = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
        if(p == v.size()){
            v.push_back(arr[i]);
            dp[i] = v.size();
        }
        else{ 
            v[p] = arr[i];
            dp[i] = p + 1;    
        }
    }
    cout << v.size() << "\n-\n";
    stack<int> st;
    int leng = v.size();
    for(int i = arr.size() - 1;i >= 0;i--){
        if(dp[i] == leng){
            st.push(arr[i]);
            leng--;
        }
    }
    while(!st.empty()){
        cout << st.top() << '\n';
        st.pop();
    }

    return 0;
}

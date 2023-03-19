// O(nlogn) (2ms, 328KB)
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    set<ll> st;
    set<ll>::iterator it = st.begin();
    st.insert(1); 
    for(int i = 0;i < 1500;i++){
        it = st.begin();
        st.insert(*it * 2);
        st.insert(*it * 3);
        st.insert(*it * 5);
        st.erase(it);
    }
    cout << "The 1500'th ugly number is " << *it << ".\n";

    return 0;
}
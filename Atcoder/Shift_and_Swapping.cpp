#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INf 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n, q, arr[200005];
int main(){
    IOS
    cin >> n >> q;
    for(int i = 0;i < n;i++) cin >> arr[i];
    int idx = 0;
    while(q--){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1){
            swap(arr[(a + idx - 1) % n], arr[(b + idx - 1) % n]);
        }
        else if(t == 2){
            idx = (idx - 1 + n) % n;
        }
        else if(t == 3){
            cout << arr[(a + idx - 1) % n] << '\n';
        }
    }

    return 0;
}
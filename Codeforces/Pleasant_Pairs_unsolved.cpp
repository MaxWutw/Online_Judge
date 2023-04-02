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
        int n;
        cin >> n;
        ll arr[100005];
        for(int i = 0;i < n;i++) cin >> arr[i];
        int cnt = 0;
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < 2 * n / arr[i];j++){
                if(i + j + 2 == arr[i] * arr[j]) cnt++;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
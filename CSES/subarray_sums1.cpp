// sliding window
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vector<int> arr(200005), prefix(200005);
int main(){
    IOS
    int n, x;
    cin >> n >> x;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    prefix[0] = 0;
    for(int i = 1;i <= n;i++){
        prefix[i] = prefix[i - 1] + arr[i];
    }
    // for(int i = 0;i <= n;i++) cout << prefix[i] << ' ';
    int cnt = 0;
    for(int l = 0, r = 0;r <= n;){
        if(prefix[r] - prefix[l] == x){
            cnt++;
            r++;
        }
        else if(prefix[r] - prefix[l] > x) l++;
        else if(prefix[r] - prefix[l] < x) r++;
    }
    cout << cnt << '\n';

    return 0;
}
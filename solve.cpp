#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
<<<<<<< HEAD
    
=======
    int n;
    while(cin >> n && n != 0){
        pair<int, int> arr[10005];
        for(int i = 0;i < n;i++){
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr, arr + n, [&](pair<int, int> a, pair<int, int> b){return a.second > b.second;});
        ll ans = 0, tp = 0;
        for(int i = 0;i < n;i++){
            ans += arr[i].first;
            if(ans + arr[i].second > tp)
                tp = (ans + arr[i].second);
        }
        cout << tp << '\n';
    }
>>>>>>> 7fad2545e4b1c5ff4888ff7226eb686a935ca136

    return 0;
}
// 雙指針
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int n, x;
vector<pair<int, int>> arr;
int main(){
    IOS
    cin >> n >> x;
    for(int i = 0;i < n;i++){
        int num, idx;
        cin >> num;
        arr.push_back({num, i + 1});
    }
    sort(arr.begin(), arr.end());
    // for(int i = 0;i < n;i++) cout << arr[i].first << ' ';
    int ans_x, ans_y;
    bool judge = false;
    for(int l = 0, r = n - 1;l < n;l++){
        for(;l < r && arr[l].first + arr[r].first > x;r--);
        if(l != r && arr[l].first + arr[r].first == x){
            judge = true;
            ans_x = arr[l].second;
            ans_y = arr[r].second;
            break;
        }
    }
    if(judge) cout << ans_y << ' ' << ans_x << '\n';
    else cout << "IMPOSSIBLE" << '\n';

    return 0;
}
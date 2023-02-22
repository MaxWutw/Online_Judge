#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n, arr[200005], dic[200005];
int search(int tar, int n_color){
    if(tar == dic[0]) return 0;
    int idx = 0;
    for(int jump = n_color / 2;jump > 0;jump >>= 1){
        while(idx + jump < n_color && dic[idx + jump] < tar)
            idx += jump;
    }
    return idx + 1;
}
int main(){
    IOS
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        dic[i] = arr[i];
    }
    sort(dic, dic + n);
    int color = 1;
    for(int i = 1;i < n;i++){
        if(dic[i] != dic[i - 1]){
            dic[color] = dic[i];
            color++;
        }
    }
    for(int i = 0;i < n;i++){
        arr[i] = search(arr[i], color);
    }
    int best = n, l = 0, r = 0, cur = 0, cnt[200005];
    memset(cnt, 0, sizeof(cnt));
    while(r < n){
        cnt[arr[r]]++;
        if(cnt[arr[r]] == 1) cur++;
        r++;
        while(cnt[arr[l]] > 1){
            cnt[arr[l]]--;
            l++;
        }
        if(cur == color) best = min(best, r - l);
    }
    cout << best << '\n';

    return 0;
}
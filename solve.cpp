#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int arr[200005], cnt[200005];
map<int, int> dic;
int main(){
    IOS
    int n;
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        dic[arr[i]] = 0;
    }
    int c = 0;
    for(auto &i : dic) i.second = c++;
    int l = 0, r = 0, best = n, cur = 0;
    while(r < n){
        cnt[dic[arr[r]]]++;
        if(cnt[dic[arr[r]]] == 1) cur++;
        r++;
        while(true){
            if(cnt[dic[arr[l]]] == 1) break;
            cnt[dic[arr[l]]]--;
            l++;
        }
        if(cur == c) best = min(best, r - l);
    }
    cout << best << '\n';

    return 0;
}
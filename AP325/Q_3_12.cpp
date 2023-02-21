// map discretization + sweep line
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int arr[200005];
map<int, int> dic;
int main(){
    IOS
    int m, n;
    cin >> m >> n;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        dic[arr[i]] = 0;
    }
    int c = 0;
    for(auto &it : dic) it.second = c++;
    int total = 0, l = 0, r = 0, cnt[200005];
    memset(cnt, 0, sizeof(cnt));
    while(r < n){
        cnt[dic[arr[r]]]++;
        while(cnt[dic[arr[r]]] > 1){
            cnt[dic[arr[l]]]--;
            l++;
        }
        if(r - l + 1 == m) total++;
        r++;
    }
    cout << total << '\n';

    return 0;
}
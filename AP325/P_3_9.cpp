// b pointer
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n, l, cnt[200005], arr[200005];
    memset(cnt, 0, sizeof(cnt));
    cin >> n >> l;
    for(int i = 0;i < n;i++) cin >> arr[i];
    int cur = 0;
    for(int i = 0;i < l;i++){
        cnt[arr[i]]++;
        if(cnt[arr[i]] == 1) cur++;
    }
    int most = cur;
    for(int left = 0, right = l;right < n;left++, right++){
        cnt[arr[right]]++;
        if(cnt[arr[right]] == 1) cur++;
        cnt[arr[left]]--;
        if(cnt[arr[left]] == 0) cur--;
        most = max(most, cur);
    }
    cout << most << '\n';

    return 0;
}
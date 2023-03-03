#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n, arr[100005];
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    int dif = 0, minimum = INF;
    for(int i = 0;i < n;i++){
        dif = max(dif, arr[i] - minimum);
        minimum = min(minimum, arr[i]);
    }
    cout << dif << '\n';

    return 0;
}
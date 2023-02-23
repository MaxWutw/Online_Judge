#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int a[100005], b[100005];
int main(){
    IOS
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    int win = 0;
    for(int i = 0, j = 0;j < n;){
        if(a[i] < b[j]){
            win++;
            i++, j++;
        }
        else j++;
    }
    cout << win << '\n';

    return 0;
}
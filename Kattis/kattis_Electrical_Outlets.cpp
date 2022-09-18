#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    IOS
    int n;
    cin >> n;
    while(n--){
        int k;
        cin >> k;
        int total = 0, tmp, cnt = 0;
        for(int i = 0;i < k;i++){
            cin >> tmp;
            total += tmp;
            cnt++;
        }
        total -= cnt;
        cout << total+1 << '\n';
    }
    
    return 0;
}
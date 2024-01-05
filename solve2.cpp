#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    int h1, m1, h2, m2;
    while(cin >> h1 >> m1 >> h2 >> m2){
        if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) break;
        int cur = (h1 * 60) + m1, alarm = (h2 * 60) + m2;
        int minu = (alarm - cur + (24 * 60)) % (24 * 60);
        cout << minu << '\n';
    }

    return 0;
}
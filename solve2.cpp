#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    int a_1 = 10, b = 10, a_2 = 10;
    if(0 == a_1 % b){
        cout << 1 << '\n';
        if(a_1 % b == a_2 % b){
            cout << 2 << '\n';
        }
    }
    else cout << 0 << '\n';

    return 0;
}
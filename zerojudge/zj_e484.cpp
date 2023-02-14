#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    int a;
    cin >> a;
    bool judge = true;
    for(int i = 2;i < a / 2 + 1;i++){
        if(a % i == 0){
            cout << "no" << '\n';
            judge = false;
            break;
        }
    }
    if(judge) cout << "yes" << '\n';

    return 0;
}
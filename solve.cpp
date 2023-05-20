#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    for(int i = 1;i <= 9;i++){
        for(int j = 1;j <= 9;j++){
            cout << i << '*' << j << '=' << i * j;
        }
        
    }

    return 0;
}
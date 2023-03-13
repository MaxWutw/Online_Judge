#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int func(){
    string str;
    cin >> str;
    ll tmp = 0;
    if(str == "IF") output *= func();
    else if(str == "END_IF") return tmp;
    else if(str == "ELSE") func();
}
int main(){
    IOS
    int n;
    cin >> n;
    while(n--){
        
    }
    return 0;
}
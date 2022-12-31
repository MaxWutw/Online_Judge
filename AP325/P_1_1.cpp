// recursion
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int cal(){
    string str;
    cin >> str;
    if(str[0] == 'f') return cal() * 2 - 1;
    else if(str[0] == 'g') return cal() + cal() * 2 - 3;
    else return stoi(str);
}
int main(){
    IOS
    int ans = cal();
    cout << ans << '\n';

    return 0;
}
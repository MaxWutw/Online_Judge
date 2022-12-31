// recursion
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int cal(){
    string str;
    cin >> str;
    if(str[0] == 'f') return 2 * cal() - 3;
    else if(str[0] == 'g') return 2 * cal() + cal() - 7;
    else if(str[0] == 'h') return 3 * cal() - 2 * cal() + cal();
    else return stoi(str);
}
int main(){
    IOS
    int ans = cal();
    cout << ans;

    return 0;
}
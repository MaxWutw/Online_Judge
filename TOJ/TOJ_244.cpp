#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    IOS
    int t;
    // cin >> t;
    string str;
    cin >> str;
    for(int i = 0;i < t;i++){
        if((int)str[i] > 90) 
            str[i] -= (1 << 5);
        else
            str[i] += (1 << 5);
    }
    for(int i = 0;i < t;i++) cout << str[i];
    cout << '\n';

    return 0;
}
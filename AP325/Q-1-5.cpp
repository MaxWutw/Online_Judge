// recursion
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
string str;
int n, cnt = 0;
int divide(int level){
    char ch = str[cnt];
    cnt++;
    if(ch == '0')  return 0;
    else if(ch == '2'){
        int total = 0;
        for(int i = 0;i < 4;i++){
            total += divide(level >> 1);
        }
        return total;
    }
    else if(ch == '1') return level * level;
}   
int main(){
    IOS
    cin >> str;
    cin >> n;
    int ans = divide(n);
    cout << ans << '\n';

    return 0;
}
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int n;
string str;
bool solve(int l, int r, int err){
    for(;l < r;l++, r--){
        if(str[l] == str[r]) continue;
        else{
            err++;
            if(err > 1) return false;
            return solve(l + 1, r, err) || solve(l, r - 1, err);
        }
    }
    // return true;
}
int main(){
    IOS
    cin >> n;
    while(n--){
        cin >> str;
        cout << (solve(0, str.size() - 1, 0) ? "YES" : "NO") << '\n';
    }

    return 0;
}
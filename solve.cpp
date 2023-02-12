#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    string str;
    cin >> str;
    ll num = str[0] - 48;
    stack<int> s;
    for(int i = 1;i < str.size() - 1;i+=2){
        if(str[i] == '*') num *= (str[i + 1] - 48);
        else if(str[i] == '/') num /= (str[i + 1] - 48);
        else if(str[i] == '-'){
            if(!s.empty()){
                s.top() -= num;
                s.pop();
            }
            else s.push((str[i + 1] - 48));
        }
        else if(str[i] == '+'){
            if(!s.empty()){
                s.top() += num;
                s.pop();
            }
            else s.push((str[i + 1] - 48));
        }
    }
    cout << num << '\n';

    return 0;
}
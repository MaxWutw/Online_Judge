// unsolved
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
    for(int i = 1;i < str.size();i+=2){
        if(str[i] == '*') num *= (str[i + 1] - 48);
        else if(str[i] == '/') num /= (str[i + 1] - 48);
        else if(str[i] == '-'){
            if(!s.empty()){
                num = s.top() - num;
                s.pop();
                s.push(num);
            }
            else{
                s.push(num);
                num = str[i + 1];
            }
        }
        else if(str[i] == '+'){
            if(!s.empty()){
                num = s.top() + num;
                s.pop();
                s.push(num);
            }
            else{
                s.push(num);
                num = str[i + 1];
            }
        }
    }
    cout << num << '\n';

    return 0;
}
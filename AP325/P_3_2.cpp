// stack
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    string str;
    while(cin >> str){
        bool judge = true;
        stack<char> s;
        for(int i = 0;i < str.size();i++){
            if(str[i] == '(' || str[i] == '[' || str[i] == '{') s.push(str[i]);
            else{
                if(s.empty() || (s.top() == '(' && str[i] != ')') || (s.top() == '[' && str[i] != ']') || (s.top() == '{' && str[i] != '}')){
                    judge = false;
                    break;
                }
                s.pop();
            }
        }
        if(!s.empty()) judge = false;
        cout << (judge ? "yes" : "no") << '\n';
    }

    return 0;
}
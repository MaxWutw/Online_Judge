#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
<<<<<<< HEAD
int arr[200005];
int main(){
    IOS
    int n;
    cin >> n;
    arr[0] = INF;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    stack<int> s;
    s.push(0);
    ll ans = 0;
    for(int i = 1;i <= n;i++){
        while(arr[s.top()] <= arr[i]) s.pop();
        ans += (i - s.top());
        s.push(i);
    }
    cout << ans << '\n';
    
=======
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

>>>>>>> refs/remotes/origin/master
    return 0;
}
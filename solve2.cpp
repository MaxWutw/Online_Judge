#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f;
using namespace std;
typedef long long ll;
ll x[505], y[505];
void print_ans(ll output[]){
    int start;
    for(int i = 504;i >= 0;i--){
        if(output[i] != 0) start = i;
    }
    for(int i = start;i >= 0;i--) cout << output[i];
}
int main(){
    IOS
    string a, b, op;
    cin >> a >> b >> op;
    cout << a << ' ' << op << ' ' << b;
    for(int i = a.size() - 1;i >= 0;i--) x[a.size() - i - 1] = a[i];
    for(int i = b.size() - 1;i >= 0;i--) y[b.size() - i - 1] = b[i];
    if(op == "+"){
        ll sum[505];
        int cnt = 0;
        for(int i = 0;i < 505;i++){
            sum[i] = x[i] + y[i] + cnt;
            if(sum[i] >= 10){
                sum[i] -= 10;
                cnt = 1;
            }
            else cnt = 0;
        }
        print_ans(sum);
    }
    else if(op == "-"){

    }
    else if(op == "*"){

    }
    else if(op == "/"){

    }

    return 0;
}
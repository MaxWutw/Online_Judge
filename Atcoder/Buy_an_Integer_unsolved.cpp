// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <sstream>
#include <cstring>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
ll a, b, x;
ll l = 0, r = 1e9;
ll cal(ll num){
    ll nnum = num, cnt = 0;
    while(nnum){
        nnum /= 10;
        cnt++;
    }
    return a * num + b * cnt;
}
int main(){
    IOS
    cin >> a >> b >> x;
    
    while(l < r){
        ll mid = (l + r) >> 1;
        ll out = cal(mid);
        if(out > x) r = mid - 1;
        else l = mid;
    }
    cout << l << '\n';

    return 0;
}
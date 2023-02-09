#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll n, p;
ll arr[40];
int main(){
    IOS
    cin >> n >> p;
    map<ll, ll> m1;
    for(int i = 0;i < n;i++) cin >> arr[i];
    m1[arr[0]] = 1;
    for(int i = 1;i < n;i++){
        map<ll, ll> m2(m1);
        for(auto e : m1){
            ll tmp = (e.first * arr[i]) % p;
            m2[tmp] = (m2[tmp] + e.second) % p;
        }
        m2[arr[i]] = (m2[arr[i]] + 1) % p;
        m1.swap(m2);
    }
    cout << m1[1] << '\n';

    return 0;
}


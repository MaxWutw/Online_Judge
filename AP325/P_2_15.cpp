// prefix sum and jump binary search
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int n, m;
int p[200005];
int main(){
    IOS
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> p[i];
    for(int i = 1;i < n;i++) p[i] += p[i - 1];
    int room = 0, total = p[n - 1];
    for(int i = 0;i < m;i++){
        int q;
        cin >> q;
        if(room != 0) q += p[room - 1];
        if(q > total){
            q -= total;
            room = 0;
        }
        if(p[room] >= q){
            room = (room + 1) % n;
            continue;
        }
        for(int jump = (n - room) / 2;jump > 0;jump >>= 1){
            while(room + jump < n && p[room + jump] < q) room += jump;
        }
        room = (room + 2) % n;
    }
    cout << room << '\n';

    return 0;
}
<<<<<<< HEAD
// #include <bits/stdc++.h>
// #define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// #define INF 0x3f3f3f3f
// #define int long long
// using namespace std;
// typedef long long ll;
// const int N = 1e5 + 5;
// int arr[15][15];
// signed main(){
//     IOS
//     int t;
//     cin >> t;
//     for(int a = 0;a < t;a++){
//         for(int i = 0;i < 10;i++){
//             string str;
//             cin >> str;
//             for(int j = 0;j < 10;j++){
//                 if(str[j] == 'X') arr[i][j] = 1;
//                 else arr[i][j] = 0;
//             }
//         }
//         int sum = 0;
//         for(int i = 0;i < 10;i++){
//             for(int j = 0;j < 10;j++){
//                 if(arr[i][j] == 1){
//                     int distance = abs(i - 5) + abs(j - 5);
//                     if (distance == 0) 
//                         sum += 5;
//                     else if (distance <= 2)
//                         sum += 4;
//                     else if (distance <= 4)
//                         sum += 3;
//                     else if (distance <= 6)
//                         sum += 2;
//                     else
//                         sum += 1;
//                 }
//             }
//         }
//         cout << sum << '\n';
//     }

//     return 0;
// }
#include <iostream>

int main() {
    int product = 1;
for(int i = 0;i < 4;i++){
    product *= 10;
}
std::cout << product ;
=======
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
#define int long long
#define lowbit(x) x&(-x)
#define L(x) (x << 1)
#define R(x) ((x << 1) | 1)
using namespace std;
// using namespace __gnu_pbds;
typedef long long ll;
const int N = 3e4 + 5;
int n, q, arr[N], dis[N], in[N];
vector<int> vec[N];
pair<int, int> ST[30][N];
vector<pair<int, int> > ett;
void dfs(int s, int dep){
    in[s] = ett.size();
    dis[s] = dep;
    ett.push_back({dep, s});
    for(auto e : vec[s]){
        dfs(e, dep + 1);
        ett.push_back({dep, s});
    }
    ett.push_back({dep, s});
}
void build(){
    for(int i = 0;i < ett.size();i++)
        ST[0][i] = {ett[i].first, ett[i].second};
    for(int i = 1;i <= log2(ett.size());i++){
        for(int j = 0;j < ett.size();j++){
            ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
        }
    }
}
pair<int, int> query(int l, int r){
    int lg = log2(r - l + 1);
    pair<int, int> res = min(ST[lg][l], ST[lg][r - (1 << lg) + 1]);
    return res;
}
signed main(){
    IOS
    cin >> n >> q;
    for(int i = 0;i <= n;i++) vec[i].clear();
    for(int i = 1;i <= n;i++){
        int inp;
        while(cin >> inp && inp) vec[i].push_back(inp);
    }
    dfs(1, 1);
    build();
    int a, b;
    while(q--){
        cin >> a >> b;
        if(in[a] > in[b]) swap(a, b);
        auto res = query(in[a], in[b]);
        cout << res.second << ' ' << dis[a] + dis[b] - 2 * dis[res.second] << '\n';
    }
>>>>>>> d2c1098d81abb1237066b1f494a38fc532b7347f

    return 0;
}


#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
vector<pair<double, double>> vec;
int main(){
    IOS
    int n, a;
    cin >> n >> a;
    for(int i = 0;i < n;i++){
        double x, y;
        cin >> x >> y;
        vec.emplace_back(x, y);
    }
    sort(vec.begin(), vec.end());

    return 0;
}
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
pair<double, double> p[15];
int main(){
    IOS
    int n;
    while(cin >> n){
        for(int i = 0;i < n;i++){
            cin >> p[i].first >> p[i].second;
        }
        p[n] = p[0];
        double area = 0.0;
        for(int i = 0;i < n;i++){
            area += p[i].first * p[i + 1].second - p[i].second * p[i + 1].first;
        }
        cout << fixed << setprecision(2) << fabs(area / 2.0) << '\n';
    }

    return 0;
}
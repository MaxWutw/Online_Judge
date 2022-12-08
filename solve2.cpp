#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
vector<pair<double, double>> vec;
template<typename T>
pair<T, T> operator - (pair<T, T> a, pair<T, T> b){
    return make_pair(a.first - b.first, a.second - b.second)
}
template<typename T>
T cross(pair<T, T> a, pair<T, T> b){
    return a.first * b.second - a.second * b.first;
}
template<typename T>
vector<pair<T, T>> ConvexHull(vector<pair<T, T>> &vec){
    sort(vec.begin(), vec.end());
    vector<pair<T, T>> hull;
}
int main(){
    IOS
    int n, a;
    cin >> n >> a;
    for(int i = 0;i < n;i++){
        double x, y;
        cin >> x >> y;
        vec.emplace_back(x, y);
    }
    double origin = 0.0, convex = 0.0;
    for(int i = 2;i < n;i++){
        origin += cross(vec[i - 1] - vec[0], vec[i] - vec[0]);
    }
    origin /= 2;
    vector<pair<double, double>> CH = ConvexHull(vec);
    for(int i = 2;i < n;i++){
        convex += cross(CH[i - 1] - CH[0], CH[i] - CH[0]);
    }
    convex /= 2;
    cout << (int)ceil((origin - convex)) / a << '\n';

    return 0;
}
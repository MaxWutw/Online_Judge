#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;

template<typename T> 
pair<T, T> operator - (pair<T, T> a, pair<T, T> b){
    return make_pair(a.first - b.first, a.second - b.second);
}

template<typename T>
T cross(pair<T, T> a, pair<T, T> b){
    return a.first * b.second - a.second * b.first;
}

template<typename T>
vector<pair<T, T>> ConvexHull(vector<pair<T, T>> &vec){
    int leng = vec.size();
    sort(vec.begin(), vec.end());
    vector<pair<T, T>> hull;
    for(int i = 0;i < 2;i++){
        int t = hull.size();
        for(auto x : vec){
            if(hull.size() - t >= 2 && cross(hull[hull.size() - 1] - hull[hull.size() - 2], x - hull[hull.size() - 2]) <= 0)
                hull.pop_back();
            hull.push_back(x);
        }
        hull.pop_back();
        reverse(vec.begin(), vec.end());
    }
    return hull;
}
int main(){
    IOS
    int n;
    while(cin >> n){
        vector<pair<double, double>> vec;
        for(int i = 0;i < n;i++){
            int x, y;
            cin >> x >> y;
            vec.emplace_back(x, y);
        }
        vector<pair<double, double>> CH = ConvexHull(vec);
        double area = 0;
        for(int i = 2;i < n;i++){
            area += cross(CH[i - 1] - CH[0], CH[i] - CH[0]);
        }
        cout << fixed << setprecision(2) << area / 2.0 << '\n';
    }

    return 0;
}
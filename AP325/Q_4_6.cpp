// version 1: struct sort
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
struct item{
    ll w, f;
};
bool cmp(struct item a, struct item b){
    return a.w * b.f < b.w * a.f;
}

int main(){
    IOS
    int n;
    struct item data[100005];
    cin >> n;
    for(int i = 0;i < n;i++) cin >> data[i].w;
    for(int i = 0;i < n;i++) cin >> data[i].f;
    sort(data, data + n, cmp);
    ll total = 0, energy = data[0].w;
    for(int i = 1;i < n;i++){
        total += energy * data[i].f; 
        energy += data[i].w;
    }
    cout << total << '\n';

    return 0;
}
// version 2: pair sort
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.first * b.second < a.second * b.first;
}
int main(){
    IOS
    int n;
    cin >> n;
    pair<int, int> arr[100005];
    for(int i = 0;i < n;i++) cin >> arr[i].first;
    for(int i = 0;i < n;i++) cin >> arr[i].second;
    sort(arr, arr + n, cmp);
    ll energy = arr[0].first, total = 0;
    for(int i = 1;i < n;i++){
        total += (energy * arr[i].second);
        energy += arr[i].first;
    }
    cout << total << '\n';

    return 0;
}
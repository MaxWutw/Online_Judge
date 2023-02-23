// struct
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
struct time{
    int start, finish;
};
bool cmp(struct time a, struct time b){
    return a.finish < b.finish;
}
int main(){
    IOS
    struct time arr[100005];
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i].start >> arr[i].finish;
    sort(arr, arr+n, cmp);
    int timing = -1, total = 0;
    for(int i = 0;i < n;i++){
        if(timing < arr[i].start){
            total++;
            timing = arr[i].finish;
        }
    }
    cout << total << '\n';

    return 0;
}

// pair
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
bool cmp(pair<int, int> &a, pair<int, int> &b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int main(){
    IOS
    int n;
    cin >> n;
    pair<int, int> arr[100005];
    for(int i = 0;i < n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n, cmp);
    int endtime = arr[0].second, total = 1;
    for(int i = 1;i < n;i++){
        if(arr[i].first > endtime){
            total++;
            endtime = arr[i].second;
        }
    }
    cout << total << '\n';

    return 0;
}
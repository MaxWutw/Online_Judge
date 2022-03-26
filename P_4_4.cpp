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
// #include <bits/stdc++.h>
// #define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// using namespace std;
// int main(){
//     IOS
//     int n;
//     cin >> n;
//     vector<pair<int, int>> arr;
//     for(int i = 0;i < n;i++){
//         int s, t;
//         cin >> s >> t;
//         arr.push_back({t, s});
//     }
//     sort(arr.begin(), arr.end());
//     int timing = -1, total = 0;
//     for(int i = 0;i < n;i++){
//         if(timing < arr[i].second){
//             total++;
//             timing = arr[i].second;
//         }
//     }
//     cout << total << '\n';

//     return 0;
// }
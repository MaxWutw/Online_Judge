#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
bool cmp(int a, int b){
    return a < b;
}
int main(){
    IOS
    int arr[10] = {42, 32, 55, 5, 83, 9, 63};
    sort(arr, arr + 7, cmp);
    for(int i = 0;i < 7;i++) cout << arr[i] << ' ';

    return 0;
}
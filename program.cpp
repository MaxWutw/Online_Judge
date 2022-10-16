#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int n, arr[100005];
int divide(int l, int r){
    if(r - l == 1) return 0;
    
}
int main(){
    IOS
    int cnt = 1;
    while(cin >> n && n){
        for(int i = 0;i < n;i++) cin >> arr[i];
        merge_sort(0, n - 1);
        cout << "Case #" << cnt++ << ':\n' << ;
    }

    return 0;
}
// Binary Search + Greedy
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
long long n, m , arr[100005];
bool judge(int num){
    int med = m, energy = num;
    for(int i = 0;i < n;i++){
        if(arr[i] >= num) return false;
        if(arr[i] < energy){
            energy -= arr[i];
            continue;
        }
        if(med == 0) return false;
        energy = num;
        med--;
        energy -= arr[i];
    }
    return true;
}
int main(){
    IOS
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> arr[i];
    int L = 0;
    for(int i = n/2;i > 0;i>>=1){
        while(!judge(L + i)){
            L += i;
        }
    }
    cout << L << '\n';

    return 0;
}
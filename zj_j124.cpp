// dfs
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll total = 0, arr[1000005], iter = 1;
void dfs(int x){
    int child = 2 + (x % 2);
    for(int i = 0;i < child;i++){
        int next = arr[iter];
        iter++;
        if(next == 0) continue;
        total += abs(x - next);
        dfs(next);
    }
}

int main(){
    IOS
    stringstream ss;
    string str;
    getline(cin, str);
    ss << str;
    int idx = 0;
    while(ss >> str){
        arr[idx] = stoi(str);
        idx++;
    }
    dfs(arr[0]);
    cout << total << '\n';

    return 0;
}
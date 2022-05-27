#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    IOS
    int n, total = 0;
    cin >> n;
    priority_queue<int> other, our;
    for(int i = 0;i < n;i++){
        int tmp;
        cin >> tmp;
        other.push(tmp);
    }
    for(int i = 0;i < n;i++){
        int tmp;
        cin >> tmp;
        our.push(tmp);
    }
    for(int i = 0;i < n;i++){
        if(our.top() > other.top()) total++;
        our.pop();other.pop();
    }
    cout << total << '\n';

    return 0;
}
// version 1: priority queue
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    int n;
    cin >> n;
    priority_queue<int> a, b;
    for(int i = 0;i < n;i++){
        int tmp;
        cin >> tmp;
        a.push(tmp);
    }
    for(int i = 0;i < n;i++){
        int tmp;
        cin >> tmp;
        b.push(tmp);
    }
    int win = 0;
    while(!a.empty()){
        if(b.top() > a.top()){
            b.pop();
            a.pop();
            win++;
        }
        else a.pop();
    }
    cout << win << '\n';

    return 0;
}

// version 2: sort + greedy
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int a[100005], b[100005];
int main(){
    IOS
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    int win = 0;
    for(int i = 0, j = 0;j < n;){
        if(a[i] < b[j]){
            win++;
            i++, j++;
        }
        else j++;
    }
    cout << win << '\n';

    return 0;
}
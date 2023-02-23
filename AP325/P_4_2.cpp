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
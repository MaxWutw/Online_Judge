#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
void balance(multiset<int, greater<int> > &left, multiset<int, less<int> > &right){
    while(left.size() > right.size()){
        right.insert(*left.begin());
        left.erase(left.begin());
    }
    while(left.size() < right.size()){
        left.insert(*right.begin());
        right.erase(right.begin());
    }
}
int main(){
    IOS
    int n, k, arr[200005];
    cin >> n >> k;
    for(int i = 0;i < n;i++) cin >> arr[i];
    multiset<int, greater<int> > left;
    multiset<int, less<int> > right;
    for(int i = 0;i < n;i++){
        if(!left.size() || arr[i] <= *left.begin()) left.insert(arr[i]);
        else right.insert(arr[i]);
        if(i >= k){
            if(left.size() && arr[i - k] <= *left.begin())
                left.erase(left.find(arr[i - k]));
            else right.erase(right.find(arr[i - k]));
        }
        balance(left, right);
        if(i >= k - 1) cout << *left.begin() << ' ';
    }
    cout << '\n';

    return 0;
}
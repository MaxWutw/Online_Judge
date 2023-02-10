#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
void foo(int (&arr) ){
    for(int i = 0;i < 5;i++) cout << arr[i] << ' ';
}
int main(){
    IOS
    int a[10] = {1, 2, 3, 5, 7};
    foo(a);

    return 0;
}
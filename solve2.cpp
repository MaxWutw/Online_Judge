// #include <bits/stdc++.h>
// #define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// #define INF 0x3f3f3f3f
// #define int long long
// using namespace std;
// typedef long long ll;
// const int N = 1e5 + 5;
// int arr[15][15];
// signed main(){
//     IOS
//     int t;
//     cin >> t;
//     for(int a = 0;a < t;a++){
//         for(int i = 0;i < 10;i++){
//             string str;
//             cin >> str;
//             for(int j = 0;j < 10;j++){
//                 if(str[j] == 'X') arr[i][j] = 1;
//                 else arr[i][j] = 0;
//             }
//         }
//         int sum = 0;
//         for(int i = 0;i < 10;i++){
//             for(int j = 0;j < 10;j++){
//                 if(arr[i][j] == 1){
//                     int distance = abs(i - 5) + abs(j - 5);
//                     if (distance == 0) 
//                         sum += 5;
//                     else if (distance <= 2)
//                         sum += 4;
//                     else if (distance <= 4)
//                         sum += 3;
//                     else if (distance <= 6)
//                         sum += 2;
//                     else
//                         sum += 1;
//                 }
//             }
//         }
//         cout << sum << '\n';
//     }

//     return 0;
// }
#include <iostream>

int main() {
    int product = 1;
for(int i = 0;i < 4;i++){
    product *= 10;
}
std::cout << product ;

    return 0;
}


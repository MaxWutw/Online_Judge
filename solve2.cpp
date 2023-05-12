#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N=105,MaxW=100005;
int v[N],w[N];
int dp[MaxW];

void Knapsack(int n,int W){

    for(int i=1;i<=n;i++){ // 遍歷每個物品
    
        for(int j=W;j>0;j--){ // 從大到小遍歷重量
        
            if(j>=w[i]) dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
}
void reKnapsack(int n,int W){

    for(int j=W;j>0;j--){ // 從大到小遍歷重量
    
        for(int i=1;i<=n;i++){ // 遍歷每個物品
        
            if(j>=w[i]) dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
}
int main(){
    IOS
    dp[0] = 0;
    v[1] = 15, v[2] = 20, v[3] = 30;
    w[1] = 1, w[2] = 3, w[3] = 4;
    Knapsack(3, 4);
    for(int i = 0;i <= 4;i++) cout << dp[i] << ' ';
    cout << '\n';
    memset(dp, 0, sizeof(dp));
    reKnapsack(3, 4);
    for(int i = 0;i <= 4;i++) cout << dp[i] << ' ';

    return 0;
}
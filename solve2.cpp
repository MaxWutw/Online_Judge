#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main(){
    IOS
    int number, charge;
    printf("Enter:");
    scanf("%d", &number);
    charge = number * 300;
    if(charge < 3000){
        printf("Charge is %d\n", charge);
    }
    if(charge >= 3000){
        int charge2;
        charge2 = charge * 0.8;
        printf("Charge is %d\n", charge2);
    }

    return 0;
}
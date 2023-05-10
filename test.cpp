#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int factor(void){
  int a,b,c,judge;
  judge = 1;
  while(true==1){
    printf("input a:");
    scanf("%d",&a);
    b=a;
    while (a!=1){
      for (c=2;c<=b;c++) {
        if (a % c== 0) {
          printf("%d",c);
          a=a/c;
          if (a!=1){
            printf("*");
          }
          if (a==1 ){
            printf("=%d\n",b);
            break;
          }
          }
        }
      } 
    if (c==b){
      printf("%d是質數\n",b);
    }
    if (b<2){
      printf("請確保此值大於或等於2\n");
    }
  }
int main(){


    return 0;
}

<<<<<<< HEAD
#include <cstdio>
int fact(double n, int p){
    if(p == 0) return 1;
    else return fact(n, p - 1) * n;
}

int main(){
    double a;
    int p;
    scanf("%lf %d", &a, &p);
    printf("%lf %d", a, p);
    // printf("%lf", fact(a, p));

=======
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    printf("%f", sqrt(4));
>>>>>>> 9ddabe05c096560696c072d8c5c28b2eed7384ac
    return 0;
}
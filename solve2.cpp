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

    return 0;
}
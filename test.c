#include <stdio.h>
#include <stdint.h>
int main(){
    int32_t n;
    printf("Please enter an odd number: ");
    scanf("%d", &n);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n - i;j++){
            printf(" ");
        }
        for(int k = 1;k <= (2 * i) - 1;k++){
            printf("*");
        }
        printf("\n");
    }
    for(int i = 1;i < n;i++){
        for(int j = 1;j <= i;j++){
            printf(" ");
        }
        for(int k = 1;k <= (2 * (n - i)) - 1;k++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
int main(){
    char str[10];
    scanf("%s", str);
    printf("%c%c%c", str[1], str[0], str[2]);

    return 0;
}
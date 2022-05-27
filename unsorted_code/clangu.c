#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int a, b;
}data;
int main(){
    data *m = malloc(sizeof(data));
    // m = (data*)malloc(sizeof(data));
    m->a = 100;
    printf("%d", m->a);
    // printf("%d", sizeof(data));

    return 0;
}
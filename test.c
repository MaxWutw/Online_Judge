#include <stdio.h>
#include <stdlib.h>
int foo(){
    int n;
    n = 9382;
    return n;
}
void bar(){
    int nb;
    nb = 482;
}
int mian(){
    // int *ptr;
    int ptr = foo();
    printf("%d", ptr);
    bar();
    printf("%d", ptr);

    return 0;
}
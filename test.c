#include <stdio.h>

int main(){
    int b = 1000000000;
    void *a = (int*) &b;
    int *c = (int*) a;

    printf("%d", *c);

    return 0;
}

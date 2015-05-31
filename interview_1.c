#include <stdio.h>

int i = 1;
main(){
    int i = i;
    /* i is undefined since local i is visible once it is declared. */
    printf("%d\n", i);
}

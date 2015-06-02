#include <stdio.h>

main(){
    unsigned int a = 0xFFFFFFF7;
    unsigned char i = (unsigned char)a;
    /* change the pointer type (char *), but does not change value */
    char *b = (char *)&a;
    printf("%08x %08x\n", i, *b);
}

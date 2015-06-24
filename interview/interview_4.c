#include <stdio.h>

main(){
    unsigned char a = 0xA5; /* 1010 0101 */
    unsigned char b = ~a>>4+1; /* 1111 1111 0101 1010 >> 5 bits and get lower 8 bits */
    printf("~a=%d\n", ~a); /* 1111 1111 0101 1010 16bit register */
    printf("b=%d\n", b);
}

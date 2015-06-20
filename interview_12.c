#include <stdio.h>

main()
{
    int a = -1;
    printf("%x\n", a);
    printf("%x\n", a>>3); // arithmetic right shift on signed value, implementation defined
    unsigned int b = 0xffffffff;
    printf("%x\n", b);
    printf("%x\n", b>>3); // logic right shit on unsigned value
}

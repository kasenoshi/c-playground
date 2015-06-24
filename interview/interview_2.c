#include <stdio.h>

main(){
    int arr[] = {6, 7, 8, 9, 10};
    int *ptr = arr;
    *(ptr++) += 123; /* {129, 7, 8, 9, 10}, ptr points to 7 */
    printf("%d, %d\n", *ptr, *(++ptr)); /* printf calculate arguments from right to left, ++ptr first, ptr points to 8 */
}

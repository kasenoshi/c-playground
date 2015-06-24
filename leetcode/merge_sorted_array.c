#include <stdio.h>
#define MAX 10

void merge(int* nums1, int m, int* nums2, int n) {
    int *a_ptr = nums1 + m - 1;
    int *b_ptr = nums2 + n - 1;
    int *c_ptr = nums1 + m + n - 1;
    while(c_ptr >= nums1 && b_ptr >= nums2)
    {   
        if(a_ptr >= nums1 && *a_ptr > *b_ptr)
        {   
            *c_ptr = *a_ptr;
            a_ptr--;
        }   
        else
        {   
            *c_ptr = *b_ptr;
            b_ptr--;
        }   
        c_ptr--;
    }       
}

main()
{
    int a[MAX] = {21,27,36,42};
    int b[] = {1,6,7,8,9,10};
    int i;
    merge(a, 4, b, 6);

    for(i = 0; i < MAX; i++)
    {
        printf("%d ", a[i]);
    }
}

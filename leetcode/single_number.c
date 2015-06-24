#include<stdio.h>
int singleNumber(int* nums, int numsSize) {
    int i;
    int xor_sum = 0;
    for(i = 0; i < numsSize; i++){
        xor_sum ^= nums[i];
    }
    return xor_sum;
}
int main(){
    int nums[] = {2147483647, -2147483648, -2147483648};
    printf("%d\n", singleNumber(nums, 3));
    return 0;
}

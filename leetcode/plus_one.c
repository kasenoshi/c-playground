#include<stdio.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *ptr = &digits[digitsSize - 1];
    int *newDigits;
    int overflowBit = 0;
    while(ptr >= digits){
        (*ptr)++;
        if(*ptr >= 10){
            *ptr %= 10;
            ptr--;
        }
        else
            break;
    }
    if(ptr < digits){
        overflowBit = 1;
        *returnSize = digitsSize + 1;
        newDigits = (int *)malloc(sizeof(int) * *returnSize);
        newDigits[0] = 1;
    }
    else{
        *returnSize = digitsSize;
        newDigits = (int *)malloc(sizeof(int) * *returnSize);
    }
    int i;
    for(i = overflowBit; i < digitsSize + overflowBit; i++){
        newDigits[i] = *digits;
        digits++;
    }
    return newDigits;
}
main(){
    int returnSize = 10;
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    int *ptr = plusOne(arr, 10, &returnSize);
    int i;
    for(i = 0; i < returnSize; i++){
        printf("%d ", ptr[i]);
    }
}


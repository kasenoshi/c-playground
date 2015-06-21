#include<stdio.h>
#include<assert.h>

int contains_duplicate(int *nums, int numsSize){
    if(numsSize == 0)
        return 0;
    int i, j;
    for(i = 0; i < numsSize; i++){
        for(j = i + 1; j < numsSize; j++){
            if(nums[i] == nums[j])
                return 1;
        }
    }
    return 0;
}
main(){
    int arr1[] = {1, 2, 3 ,4 ,5};
    assert(contains_duplicate(arr1, 5) == 0);
    int arr2[] = {1, 2, 3 ,4 ,4, 6};
    assert(contains_duplicate(arr2, 6) == 1);
    int arr3[] = {};
    assert(contains_duplicate(arr3, 0) == 0);
}

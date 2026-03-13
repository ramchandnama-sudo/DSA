#include <stdlib.h>

int findSmallestInteger(int* nums, int numsSize, int value) {
    int* count = (int*)calloc(value, sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        int rem = ((nums[i] % value) + value) % value;
        count[rem]++;
    }
    
    for (int i = 0; i <= numsSize; i++) {
        if (count[i % value] > 0) {
            count[i % value]--;
        } else {
            free(count);
            return i;
        }
    }
    
    free(count);
    return numsSize;
}

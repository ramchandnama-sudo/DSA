#include <stdlib.h>
#include <limits.h>
#include <math.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxDistinctElements(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int ans = 0;
    long long pre = LLONG_MIN;
    
    for (int i = 0; i < numsSize; i++) {
        long long low = (long long)nums[i] - k;
        long long high = (long long)nums[i] + k;
        
        long long current_val;
        if (pre + 1 < low) {
            current_val = low;
        } else {
            current_val = pre + 1;
        }
        
        if (current_val <= high) {
            ans++;
            pre = current_val;
        }
    }
    
    return ans;
}

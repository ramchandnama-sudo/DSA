#include <stdbool.h>

bool hasIncreasingSubarrays(int* nums, int numsSize, int k) {
    if (k == 1) return numsSize >= 2; 
    
    int prev_inc = 0;
    int curr_inc = 1;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            curr_inc++;
        } else {
            prev_inc = curr_inc;
            curr_inc = 1;
        }
        
        if (curr_inc >= 2 * k || (prev_inc >= k && curr_inc >= k)) {
            return true;
        }
    }
    
    return false;
}

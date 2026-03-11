#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxIncreasingSubarrays(int* nums, int numsSize) {
    int maxK = 0;
    int prevLen = 0;
    int currLen = 1;
    
    for (int i = 1; i <= numsSize; i++) {
       
        if (i < numsSize && nums[i] > nums[i-1]) {
            currLen++;
        } else {
           
            maxK = MAX(maxK, currLen / 2);
            
           
            if (prevLen > 0) {
                maxK = MAX(maxK, MIN(prevLen, currLen));
            }
            
            
            prevLen = currLen;
            currLen = 1;
        }
    }
    
    return maxK;
}

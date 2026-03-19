#include <stdlib.h>

#define MAX_VAL 200005
#define OFFSET 100000

int maxFrequency(int* nums, int numsSize, int k, int numOperations) {
    int* cnt = (int*)calloc(MAX_VAL, sizeof(int));
    int* diff = (int*)calloc(MAX_VAL + 1, sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i] + OFFSET;
        cnt[x]++;
        
        int start = (x - k < 0) ? 0 : x - k;
        int end = (x + k + 1 > MAX_VAL) ? MAX_VAL : x + k + 1;
        
        diff[start]++;
        diff[end]--;
    }

    int ans = 0;
    int current_coverage = 0;
    for (int i = 0; i < MAX_VAL; i++) {
        current_coverage += diff[i];
        
        int others = current_coverage - cnt[i];
        int can_change = (others < numOperations) ? others : numOperations;
        int total = cnt[i] + can_change;
        
        if (total > ans) ans = total;
    }

    free(cnt);
    free(diff);
    return ans;
}
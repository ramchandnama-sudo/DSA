#include <stdio.h>
#include <stdlib.h>

// Helper function to calculate GCD using Euclidean algorithm
int getGcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// FIXED: Return type changed to long long to match LeetCode's signature
long long gcdSum(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    // Dynamically allocate array for prefixGcd
    int* prefixGcd = (int*)malloc(numsSize * sizeof(int));
    
    // FIXED: Correctly initialized to the value of the first element
    int current_max = nums[0];
    
    // Step 1: Construct the prefixGcd array
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > current_max) {
            current_max = nums[i];
        }
        prefixGcd[i] = getGcd(nums[i], current_max);
    }
    
    // Step 2: Sort the array in non-decreasing order
    qsort(prefixGcd, numsSize, sizeof(int), compare);
    
    // Step 3: Form pairs using a two-pointer approach
    long long total_sum = 0; // Uses long long to prevent integer overflow
    int left = 0;
    int right = numsSize - 1;
    
    while (left < right) {
        total_sum += getGcd(prefixGcd[left], prefixGcd[right]);
        left++;
        right--;
    }
    
    // Free the dynamically allocated memory to prevent leaks
    free(prefixGcd);
    
    return total_sum;
}


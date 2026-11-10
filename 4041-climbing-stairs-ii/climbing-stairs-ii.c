#include <limits.h>
#include <stdlib.h>

int climbStairs(int n, int* costs, int costsSize) {
    int* dp = (int*)malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) {
        dp[i] = INT_MAX / 2;
    }

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = (i - 3 > 0 ? i - 3 : 0); j < i; j++) {

            int jump = i - j;
            int totalCost = dp[j] + costs[i - 1] + jump * jump;

            if (totalCost < dp[i]) {
                dp[i] = totalCost;
            }
        }
    }

    int ans = dp[n];

    free(dp);

    return ans;
} 
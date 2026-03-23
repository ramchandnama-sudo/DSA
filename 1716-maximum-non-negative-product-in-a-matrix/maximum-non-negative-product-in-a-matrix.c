#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxProductPath(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    long long max_dp[m][n];
    long long min_dp[m][n];

    max_dp[0][0] = min_dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++) {
        max_dp[i][0] = min_dp[i][0] = max_dp[i - 1][0] * grid[i][0];
    }

    for (int j = 1; j < n; j++) {
        max_dp[0][j] = min_dp[0][j] = max_dp[0][j - 1] * grid[0][j];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] >= 0) {
                max_dp[i][j] = MAX(max_dp[i - 1][j], max_dp[i][j - 1]) * grid[i][j];
                min_dp[i][j] = MIN(min_dp[i - 1][j], min_dp[i][j - 1]) * grid[i][j];
            } else {
                max_dp[i][j] = MIN(min_dp[i - 1][j], min_dp[i][j - 1]) * grid[i][j];
                min_dp[i][j] = MAX(max_dp[i - 1][j], max_dp[i][j - 1]) * grid[i][j];
            }
        }
    }

    long long res = max_dp[m - 1][n - 1];
    return res < 0 ? -1 : (int)(res % 1000000007);
}
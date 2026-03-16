#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

void update_top3(int* top, int* size, int val) {
    for (int i = 0; i < *size; i++) if (top[i] == val) return;
    top[(*size)++] = val;
    qsort(top, *size, sizeof(int), compare);
    if (*size > 3) *size = 3;
}

int* getBiggestThree(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int m = gridSize, n = gridColSize[0];
    int top3[4], top_size = 0;
    
    int d1[102][102] = {0}, d2[102][102] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            d1[i + 1][j + 1] = d1[i][j] + grid[i][j];
            d2[i + 1][j + 1] = d2[i][j + 2] + grid[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            update_top3(top3, &top_size, grid[i][j]);
            for (int k = 1; i + 2 * k < m && j - k >= 0 && j + k < n; k++) {
                int sum = (d1[i + k + 1][j + k + 1] - d1[i][j]) +
                          (d1[i + 2 * k + 1][j + 1] - d1[i + k][j - k]) +
                          (d2[i + k + 1][j - k + 1] - d2[i][j + 2]) +
                          (d2[i + 2 * k + 1][j + 1] - d2[i + k][j + k + 2]) -
                          grid[i][j] - grid[i + 2 * k][j] - grid[i + k][j - k] - grid[i + k][j + k];
                update_top3(top3, &top_size, sum);
            }
        }
    }

    *returnSize = top_size;
    int* res = (int*)malloc(top_size * sizeof(int));
    memcpy(res, top3, top_size * sizeof(int));
    return res;
}

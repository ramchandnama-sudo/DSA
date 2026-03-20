#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** minAbsDiff(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    int m = gridSize;
    int n = gridColSize[0];
    int res_rows = m - k + 1;
    int res_cols = n - k + 1;

    *returnSize = res_rows;
    *returnColumnSizes = (int*)malloc(res_rows * sizeof(int));
    int** ans = (int**)malloc(res_rows * sizeof(int*));

    int* sub_elements = (int*)malloc(k * k * sizeof(int));

    for (int i = 0; i < res_rows; i++) {
        (*returnColumnSizes)[i] = res_cols;
        ans[i] = (int*)malloc(res_cols * sizeof(int));
        for (int j = 0; j < res_cols; j++) {
            int count = 0;
            for (int r = i; r < i + k; r++) {
                for (int c = j; c < j + k; c++) {
                    sub_elements[count++] = grid[r][c];
                }
            }

            qsort(sub_elements, count, sizeof(int), compare);

            int min_diff = INT_MAX;
            int found_distinct = 0;
            for (int idx = 1; idx < count; idx++) {
                if (sub_elements[idx] != sub_elements[idx - 1]) {
                    int diff = sub_elements[idx] - sub_elements[idx - 1];
                    if (diff < min_diff) {
                        min_diff = diff;
                    }
                    found_distinct = 1;
                }
            }

            ans[i][j] = found_distinct ? min_diff : 0;
        }
    }

    free(sub_elements);
    return ans;
}
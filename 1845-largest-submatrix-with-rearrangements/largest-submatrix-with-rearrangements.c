#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int maxArea = 0;

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                matrix[i][j] += matrix[i - 1][j];
            }
        }
    }

    int* currentRow = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            currentRow[j] = matrix[i][j];
        }
        
        qsort(currentRow, n, sizeof(int), compare);
        
        for (int j = 0; j < n; j++) {
            int area = currentRow[j] * (j + 1);
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }

    free(currentRow);
    return maxArea;
}

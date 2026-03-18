int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];
    int** prefixSum = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        prefixSum[i] = (int*)malloc(n * sizeof(int));
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            long long currentSum = grid[i][j];
            if (i > 0) currentSum += prefixSum[i - 1][j];
            if (j > 0) currentSum += prefixSum[i][j - 1];
            if (i > 0 && j > 0) currentSum -= prefixSum[i - 1][j - 1];

            if (currentSum <= k) {
                prefixSum[i][j] = (int)currentSum;
                count++;
            } else {
                prefixSum[i][j] = k + 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        free(prefixSum[i]);
    }
    free(prefixSum);

    return count;
}

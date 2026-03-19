int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int ans = 0;

    int** countX = (int**)malloc((m + 1) * sizeof(int*));
    int** countY = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        countX[i] = (int*)calloc((n + 1), sizeof(int));
        countY[i] = (int*)calloc((n + 1), sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int isX = (grid[i][j] == 'X');
            int isY = (grid[i][j] == 'Y');
            
            countX[i + 1][j + 1] = countX[i][j + 1] + countX[i + 1][j] - countX[i][j] + isX;
            countY[i + 1][j + 1] = countY[i][j + 1] + countY[i + 1][j] - countY[i][j] + isY;
            
            if (countX[i + 1][j + 1] > 0 && countX[i + 1][j + 1] == countY[i + 1][j + 1]) {
                ans++;
            }
        }
    }

    for (int i = 0; i <= m; i++) {
        free(countX[i]);
        free(countY[i]);
    }
    free(countX);
    free(countY);

    return ans;
}

int** reverseSubmatrix(int** grid, int gridRows, int* gridColSize, int x, int y, int k, int* returnSize, int** returnColumnSize) {
    for (int i = 0; i < k / 2; i++) {
        for (int j = 0; j < k; j++) {
            int temp = grid[x + i][y + j];
            grid[x + i][y + j] = grid[x + k - 1 - i][y + j];
            grid[x + k - 1 - i][y + j] = temp;
        }
    }

    *returnSize = gridRows;
    *returnColumnSize = gridColSize;
    return grid;
}
#define MIN(x, y) (x < y ? (x) : (y))

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    int n = *matrixColSize;
    for (int r = n - 2; r >= 0; r--) {
        for (int c = 0; c < n; c++) {
            int best = matrix[r+1][c];
            if (c)
                best = MIN(best, matrix[r + 1][c - 1]);
            if (c + 1 < n)
                best = MIN(best, matrix[r + 1][c + 1]);
            matrix[r][c] += best;
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
        ans = MIN(ans, matrix[0][i]);
    return ans;
}
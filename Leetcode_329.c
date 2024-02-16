#define MAX(a, b) (a > b ? (a) : (b))

int dp[200][200];
int rows, cols;

int solve(int **matrix, int i, int j, int prev_val) {
    if (i < 0 || j < 0 || i >= rows || j >= cols || matrix[i][j] <= prev_val)
        return 0;
    if (dp[i][j])
        return dp[i][j];
    int a1 = solve(matrix, i+1, j, matrix[i][j]);
    int a2 = solve(matrix, i-1, j, matrix[i][j]);
    int a3 = solve(matrix, i, j+1, matrix[i][j]);
    int a4 = solve(matrix, i, j-1, matrix[i][j]);
    return dp[i][j] = 1 + MAX(MAX(a1, a2), MAX(a3, a4));
}


int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    int ans = 0;
    rows = matrixSize;
    cols = matrixColSize[0];
    for (int i = 0; i < 200; i++)
        for (int j = 0; j < 200; j++)
            dp[i][j] = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int tmp = solve(matrix, i, j, -1);
            ans = tmp > ans ? tmp : ans;
        }
    }
    return ans;
}
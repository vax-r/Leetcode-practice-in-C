#define MIN(a,b) ((a) < (b)) ? (a) : (b)

int numSquares(int n) {
    int *dp = calloc(n + 1, sizeof(int));

    for (int i=0; i < n + 1; i++) {
        dp[i] = i;
        for (int j=1; i >= j * j; j++) {
            dp[i] = MIN(dp[i], dp[i - j * j] + 1);
        }
    }

    int ans = dp[n];
    free(dp);
    return ans;
}
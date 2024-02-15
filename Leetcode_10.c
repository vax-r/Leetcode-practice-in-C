bool isMatch(char* s, char* p) {
    bool **dp = calloc(strlen(s) + 1, sizeof(bool *));
    for (int i = 0; i < strlen(s) + 1; i++)
        dp[i] = calloc(strlen(p) + 1, sizeof(bool));
    dp[0][0] = true;
    for (int i = 0; i <= strlen(s); i++) {
        for (int j = 1; j <= strlen(p); j++) {
            if (p[j-1] == '*') {
                dp[i][j] = dp[i][j-2] || ( i > 0 && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
            }
            else if (i > 0 && (p[j-1] == '.' || s[i-1] == p[j-1])) {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    return dp[strlen(s)][strlen(p)];
}
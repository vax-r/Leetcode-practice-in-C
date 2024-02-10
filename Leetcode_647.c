int palindromic(char *s, int length) {
    for (int i=0; i<length/2; i++)
        if (s[i] != s[length - 1 - i])
            return 0;
    return 1;
}

int countSubstrings(char* s) {
    int ans = 0;
    for (int l = 1; l <= strlen(s); l++) {
        for (int i = 0; i <= strlen(s) - l; i++) {
            ans += palindromic(s + i, l);
        }
    }
    return ans;
}
bool isPalindrome(char* s) {
    char *valid_s = calloc(strlen(s) + 1, sizeof(char));
    int k = 0;
    for (int i = 0; i < strlen(s); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            valid_s[k] = s[i];
            k++;
        }
    }

    int start = 0, end = k - 1;
    while (start < end) {
        if (tolower(valid_s[start]) != tolower(valid_s[end])) {
            free(valid_s);
            return false;
        }
        start += 1;
        end -= 1;
    }
    free(valid_s);
    return true;
}
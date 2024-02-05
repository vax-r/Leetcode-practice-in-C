int firstUniqChar(char* s) {
    int table[26] = {0};
    for (int i=0; i<strlen(s); i++)
        table[s[i] % 26] += 1;

    int unique = -1;
    for (int i=0; i < strlen(s); i++) {
        if (table[s[i] % 26] == 1) {
            unique = i;
            break;
        }
    }

    return unique;
}
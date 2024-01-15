int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

bool closeStrings(char* word1, char* word2) {
    if (strlen(word1) != strlen(word2))
        return false;
    bool *exist1 = calloc(26, sizeof(bool));
    bool *exist2 = calloc(26, sizeof(bool));
    for (int i=0; i<strlen(word1); i++) {
        exist1[word1[i] % 26] = true;
        exist2[word2[i] % 26] = true;
    }
    for (int i=0; i<26; i++)
        if (exist1[i] != exist2[i]) {
            free(exist1);
            free(exist2);
            return false;
        }
    free(exist1);
    free(exist2);

    int *count1 = calloc(26, sizeof(int));
    int *count2 = calloc(26, sizeof(int));
    for (int i=0; i<strlen(word1); i++) {
        count1[word1[i] % 26] += 1;
        count2[word2[i] % 26] += 1;
    }

    qsort(count1, 26, sizeof(int), cmpfunc);
    qsort(count2, 26, sizeof(int), cmpfunc);
    for (int i=0; i<26; i++)
        if(count1[i] != count2[i]) {
            free(count1);
            free(count2);
            return false;
        }
    
    free(count1);
    free(count2);
    return true;
}
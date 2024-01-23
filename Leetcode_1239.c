#define MAX(a, b) ((a) > (b)) ? (a) : (b)

int maxLength(char** arr, int arrSize) {
    int ans = 0;
    unsigned *converted = calloc(arrSize, sizeof(unsigned));
    unsigned *combination = calloc(1 << arrSize, sizeof(unsigned));
    int k = 0, comb_len = 0;
    for (int i = 0; i < arrSize; i++) {
        unsigned tmp = 0U;
        for (int j = 0; j < strlen(arr[i]); j++)
            tmp |= 1 << (arr[i][j] - 'a');
        if (strlen(arr[i]) != __builtin_popcount(tmp))
            continue;
        converted[k++] = tmp;
    }

    combination[comb_len++] = 0U;

    for (int i = 0; i < k; i++) {
        for (int j = comb_len - 1; j >= 0; j--) {
            unsigned tmp = combination[j];
            if (tmp & converted[i])
                continue;
            combination[comb_len++] = (tmp | converted[i]);
        }
    }

    for (int i = 0; i < comb_len; i++)
        ans = MAX(ans, __builtin_popcount(combination[i]));

    free(converted);
    free(combination);
    return ans;
}
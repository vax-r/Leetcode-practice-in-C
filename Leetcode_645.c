int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    int *ans = calloc(2, sizeof(int));

    int *table = calloc(numsSize, sizeof(int));
    for (int i=0; i<numsSize; i++)
        table[nums[i] - 1]++;

    int k=0;
    for (int i=0; i<numsSize; i++) {
        if (table[i] == 2)
            ans[0] = i + 1;
        if (table[i] == 0)
            ans[1] = i + 1;
    }
    free(table);
    return ans;
}
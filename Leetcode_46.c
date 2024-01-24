void permute_generate(int *nums, int numsSize, int nums_idx, int **retArr, int *Arr_idx) {
    if (nums_idx == numsSize - 1) {
        memcpy(retArr[*Arr_idx], nums, sizeof(int) * numsSize);
        *Arr_idx += 1;
        return;
    }

    for (int i = nums_idx; i < numsSize; i++) {
        int tmp = nums[nums_idx];
        nums[nums_idx] = nums[i];
        nums[i] = tmp;
        permute_generate(nums, numsSize, nums_idx + 1, retArr, Arr_idx);
        tmp = nums[nums_idx];
        nums[nums_idx] = nums[i];
        nums[i] = tmp;
    }
    return;
}


int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int size = 1;
    for (int i=1; i<=numsSize; i++)
        size *= i;
    int **retArr = calloc(size, sizeof(int *));
    *returnColumnSizes = calloc(size, sizeof(int));
    *returnSize = size;
    for (int i=0; i < size; i++) {
        retArr[i] = calloc(numsSize, sizeof(int));
        (*returnColumnSizes)[i] = numsSize;
    }
    int currIdx = 0;
    permute_generate(nums, numsSize, 0, retArr, &currIdx);
    return retArr;
}
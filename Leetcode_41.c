int firstMissingPositive(int* nums, int numsSize) {
    for (int i=0; i < numsSize; i++)
        if (nums[i] <= 0 || nums[i] > numsSize)
            nums[i] = numsSize + 1;

    for (int i=0; i < numsSize; i++) {
        int num = abs(nums[i]);
        if (num == numsSize + 1)
            continue;
        if (nums[num - 1] > 0)
            nums[num - 1] = -nums[num - 1];
    }

    for (int i = 0 ; i < numsSize; i++)
        if (nums[i] >= 0)
            return i + 1;
    return numsSize + 1;
}
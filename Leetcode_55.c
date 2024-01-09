bool canJump(int* nums, int numsSize) {
    bool *reach = calloc(numsSize, sizeof(bool));
    reach[0] = true;
    for (int i = 0; i < numsSize; i++)
        for (int j = 1; reach[i] && j <= nums[i] && i+j < numsSize; j++)
            reach[i + j] = true;

    bool ans = reach[numsSize - 1];
    free(reach);
    return ans;
}
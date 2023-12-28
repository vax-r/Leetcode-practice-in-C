/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        int num = abs(nums[i]);
        if (nums[num - 1] > 0)
            nums[num - 1] = -nums[num - 1];
    }
    int count = 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i] > 0)
            count++;
    *returnSize = count;
    int *ans = calloc(count, sizeof(int));
    int k = 0;
    for (int i=0; i<numsSize; i++)
        if (nums[i] > 0)
            ans[k++] = i+1;
    return ans;
}
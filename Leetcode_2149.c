/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    int *pos = calloc(numsSize >> 1, sizeof(int)), p_ind = 0;
    int *neg = calloc(numsSize >> 1, sizeof(int)), n_ind = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            pos[p_ind] = nums[i];
            p_ind += 1;
        } else {
            neg[n_ind] = nums[i];
            n_ind += 1;
        }
    }

    int k = 0;
    for (int i = 0; i < numsSize >> 1; i++) {
        nums[k] = pos[i];
        k += 1;
        nums[k] = neg[i];
        k += 1;
    }
    free(pos);
    free(neg);
    *returnSize = numsSize;
    return nums;
}